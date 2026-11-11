#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,cnt;
ll a[200005],sum;
char b[200005];
struct fx{ll p;char q;};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll x;char y;
		cin>>x>>y;
		sum+=x;
		if(y==b[cnt])a[cnt]+=x;
		else{a[++cnt]=x,b[cnt]=y;}
	}
	n=cnt;
	vector<fx>l,r;
	ll s=0;
	int z=1;
	for(int i=1;i<=n;i++)
	{
		z=i;
		if(s+a[i]<=sum/2)
		{
			s+=a[i];
			l.push_back({a[i],b[i]});
			a[i]=0;
		}
		else if(s==sum/2)
		{
			break;
		}
		else 
		{
			l.push_back({sum/2-s,b[i]});
			a[i]-=sum/2-s;
			break;
		}
	}
	if(sum%2==1)a[z]--;
	for(int i=n;i>0;i--)
	{
		if(a[i]==0)break;
		r.push_back({a[i],b[i]});
	}
	ll ans=0;
	for(int i=0,j=0;i<l.size(),j<r.size();i++)
	{
		while(l[i].p>0&&j<r.size())
		{
			if(l[i].q==r[j].q)
			{
				if(l[i].p>=r[j].p)
				{
					l[i].p-=r[j].p;
					r[j].p=0;
					j++;
				}
				else 
				{
					r[j].p-=l[i].p;		
					l[i].p=0;			
				}
			}
			else 
			{
				if(l[i].p>=r[j].p)
				{
					ans+=r[j].p;
					l[i].p-=r[j].p;
					r[j].p=0;
					j++;
				}
				else 
				{
					ans+=l[i].p;
					r[j].p-=l[i].p;	
					l[i].p=0;				
				}
			}
		}
		/*for(auto x:l)cout<<x.p<<' ';
		cout<<'\n';
		for(auto x:r)cout<<x.p<<' ';
		cout<<'\n';
		cout<<'\n';
		cout<<'\n';*/
	}
	cout<<ans;
	return 0;
}
