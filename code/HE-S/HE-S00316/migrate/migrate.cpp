#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[10005],maxn,ans;
void dfs(int q,int z,int nn)
{
	if(q>z){
		if(nn<=maxn)
		{
			if(nn<maxn)n=0;
			n++;	
		}
		return;
	}
	for(int i = q+1;i<=n;i++)
	{
		if(a[i]-a[q]<=d)dfs(i,z,nn+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>c>>t;
    for(int w=1;w<=t;w++){
    	cin>>n>>d;
    	for(int i = 1;i<=n;i++)
    	{
    		cin>>a[i];
		}
		if(n<=3)cout<<0<<"\n";
		else{
			for(int i = 1;i<=n-3;i++)
			{
				for(int j = i+3;j<=n;j++)
				{
					dfs(i,j,0);
					if(n==2)ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
