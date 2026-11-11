#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool st;
const int N=5e5+5;
ll a[N],sum[N];
int nxt[N];
int n;
ll m;
ll maxx,minn,l,r,s,ans;
bool ed;
bool check(int x)
{
	int id=-1;
	for(int i=1;i<n;i++)
	{
		if(x==a[i])
		{
			id=i;
			break;
		}
		else if(x>a[i]&&x<a[i+1])
		{
			id=i;
			break;
		}
	}
	if(id==-1) id=n;
	ll cnt=0;
	for(int i=1;i<=id;i++)
	{
		cnt=cnt+abs(x-a[i]);
	}
//	cout << cnt << endl ;
	return cnt<=m;
}
signed main() 
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	maxx=LLONG_MIN;
	minn=LLONG_MAX;
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	l=a[1];
	r=a[n];
	while(l<=r)
	{
		ll mid=(l+r)>>1;
//		cout << l << " " << r << endl ;
		if(check(mid))
		{
			l=mid+1;
			s=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	int seat=-1,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=s) 
		{
			tot=tot+s-a[i];
			ans++;
		}
		else
		{
			seat=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(a[j]==a[i]) j++;
		nxt[i]=j-1;
//		cout << i << " " << nxt[i] << endl ;
		i=j-1;
	}
	for(int i=seat;i<=n;i++)
	{
//		cout<<"i "<<i<<endl;
		int p=nxt[i];
//		cout << p << endl ;
		int val=a[i];
		l=1,r=i-1,s=-1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
//			cout << l << " " << r << " " << mid << " " ;
			if(val*(i-(mid-1))-(sum[i]-sum[mid-1])<=m)
			{
//				cout<<"Yes ";
				r=mid-1;
				s=mid;
			}
			else
			{
//				cout << "No\n" ;
				l=mid+1; 
			}
//			cerr<<r<<" "<<mid<<" "<<l<<endl;
			if(l>r) break;
		}
//		cout << " ----------------------------- "  << p << " " << s << endl ;
		i=p;
		if(s==-1) continue;
//		if(i - s + 1 > ans) cout << i << " " << s << endl ;
		ans=max(ans,i-s+1);
		if(p==0) break;
	}
	printf("%lld\n",ans);
	return 0;
}
