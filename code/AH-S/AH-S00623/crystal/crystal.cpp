#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],f[500005],c[500005];
int ans=1;
void dfs(int k,int g,int s)
{
	if(k<=m)  ans=max(ans,g);
	if(k>=m) return ;
	for(int i=s;i<=n;i++)
	{
		if(f[i]==1) continue;
		f[i]=1;
		int g1=g+1,k1=k+abs(a[i]-a[s])*g;
		dfs(k1,g1,a[i]);
		f[i]=0;
	}
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5000)
	{
		for(int i=1;i<=n;i++) f[i]=0;
		for(int i=1;i<=n;i++)
		{
			f[a[i]]=1;
			dfs(0,1,a[i]);
			f[a[i]]=0;
		}
		cout<<ans;
	}
	else
	{
		for(int i=2;i<=n;i++) c[i]=a[i]-a[i-1];
		int l=1,r=1,s=0,cs=0,b=2;
		while(r<=n)
		{
			if(l==r)
			{
				r++;
				s=a[r],cs=a[r];
			}
			else if(s>m)
			{
				l++;
				s-=cs,cs-=c[l-1];
				b--;
			}
			else
			{
				ans=max(ans,r-l+1);
				r++;
				s+=c[r]*b,cs+=c[r];
				b++;
			}
		}
		cout<<ans;
	}
	return 0;
}
