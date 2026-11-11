#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],b[N],d,maxn;
void print(__int128 x)
{
	if(x<10) putchar(x+'0');
	else
	{
		print(x/10);
		putchar(x%10+'0');
	}
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],maxn=max(maxn,llabs(a[i]));
	if(maxn<=100)
	{
		ll ans=0;
		for(int i=-100;i<=100;++i)
		{
			for(int j=1;j<=n;++j)
				if(a[j]<=i) b[j]=i-a[j];
				else b[j]=0x3f3f3f3f3f3f3f3f;
			sort(b+1,b+n+1);
			ll s=0,sum=0;
			for(int j=1;j<=n;++j)
				if(s+b[j]<=m)
				{
					s+=b[j];
					sum+=1;
				}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	if(n<=5000)
	{
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				if(a[j]<=a[i]) b[j]=a[i]-a[j];
				else b[j]=0x3f3f3f3f3f3f3f3f;
			sort(b+1,b+n+1);
			ll s=0,sum=0;
			for(int j=1;j<=n;++j)
				if(s+b[j]<=m)
				{
					s+=b[j];
					sum+=1;
				}
			ans=max(ans,sum);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	m/=d;
	__int128 l=0,r=1e18,ans;
	while(l<=r)
	{
		__int128 mid=l+(r-l)/2;
		if(mid*(mid+1)/2>m) r=mid-1,ans=mid;
		else if(mid*(mid+1)/2==m)
		{
			print(mid);
			return 0;
		}
		else l=mid+1;
	}
	print(ans);
	return 0;
}
