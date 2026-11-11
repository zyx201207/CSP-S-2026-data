#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,t,ans,sum,minn,a[500005],pre[500005];
void check(int l,int r,int st)
{
	if(l==r)
	{
		if(minn>st) minn=st,sum=1;
		else sum++;
	}
	else for(int i=l+1;i<=r;i++) if(a[i]-a[l]<=m) check(i,r,st+1);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++)
		{
			for(int j=4;j<=n;j++)
			{
				minn=INT_MAX,sum=0,check(i,j,0);
				if(sum==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
