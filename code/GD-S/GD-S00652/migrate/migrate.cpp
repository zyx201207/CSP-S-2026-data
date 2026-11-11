#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+10;
const ll p[3]={410492603,778330457,829383661};
ll f[3][N],s[3][N];
ll x[N],pre[N],suf[N],dis[N];
ll c,t,n,d;
ll solveA()
{
	if(n==1) return 0;
	d/=x[2]-x[1];
	if(d<=1) return 0;
	return max(0ll,n-2*d+1);
}
ll solven2()
{
	ll w=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(x[i]-x[w]>d) w++;
		pre[i]=w;
	}
	w=n;
	for(int i=n;i>=1;i--)
	{
		while(x[w]-x[i]>d) w--;
		suf[i]=w; 
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j<=n;j++) 
		{
			dis[j]=0;
			for(int k=0;k<3;k++) f[k][j]=s[k][j]=0;
		}
		ll x=i,bs=1; dis[i]=0;
		while(x!=suf[x])
		{
			for(int j=x+1;j<=suf[x];j++) dis[j]=bs;
			x=suf[x],bs++;
		}
		ll be=i; 
		for(int j=0;j<3;j++) f[j][i]=s[j][i]=1;
		for(int j=i+1;j<=x;j++)
		{
			if(dis[j]!=dis[be]) be=j;
			for(int k=0;k<3;k++)
			{
				f[k][j]=(s[k][be-1]-s[k][pre[j]-1]+p[k])%p[k];
				s[k][j]=(s[k][j-1]+f[k][j])%p[k];
			}
		}
		for(int j=i+1;j<=x;j++) 
			ans+=(f[0][j]==2&&f[1][j]==2&&f[2][j]==2);
	}
	return ans;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(11<=c&&c<=12) cout<<solveA()<<"\n"; 
		else cout<<solven2()<<"\n";
	}
	return 0;
}
/*
10 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
