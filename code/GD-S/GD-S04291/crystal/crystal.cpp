#include<bits/stdc++.h>
#define ll long long
#define N 500500
using namespace std;

ll n,m,ans=0;
ll a[N],b[N],c[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	c[0]=c[1]=0;
	for(int i=2;i<=n;i++) 
	{
		c[i]=(a[i]-a[i-1]);
		b[i]=b[i-1]+c[i];
	}
	ll l=1,cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt+=c[i]*(i-l);
		while(cnt>m && l<i) 
		{
			cnt-=b[i]-b[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
