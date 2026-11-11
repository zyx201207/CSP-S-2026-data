#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],ans,l,f[N],que[N],r,buck[N],g[N];
void sol()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	ans=0;
	for(int i=1;i<n;i++)
	{
		l=1,r=1,que[1]=i;
		for(int j=0;j<=n;j++)f[j]=1e9,buck[j]=0,g[j]=0;
		f[i]=0,g[i]=1,buck[0]=1;
		for(int j=i+1;j<=n;j++)
		{
			while(l<=r&&x[j]-x[que[l]]>d)
			{
				buck[f[que[l]]]-=g[que[l]];
				l++;
			}
			f[j]=f[que[l]]+1;
			if(f[j]<1000000000)
			{
				if(buck[f[j]-1]==2)ans++;
				g[j]+=buck[f[j]-1];
			}
			while(l<=r&&f[j]<f[que[r]])
			{
				buck[f[que[r]]]-=g[que[r]];
				r--;
			}
			if(f[j]<1000000000)que[++r]=j,buck[f[j]]+=g[j];
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)sol();
	}
	return 0;
}
