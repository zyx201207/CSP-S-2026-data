#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int f[200005];
long long Max=-1;
void dfs(int level,long long ans)
{
	if(level<=0)
		Max=max(Max,ans);
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(level-1,(ans&a[i]));
			f[i]=0;
		}
	}
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    if(m==1)
    {
    	for(int i=0;i<n;i++)
    	{
    		Max=max(Max,a[i]);
		}
	}
	else
	{
	    for(int i=0;i<n;i++)
	    {
	    	f[i]=1;
	    	dfs(m-1,a[i]);
	    	f[i]=0;
	    }
	}
    cout<<Max;
    return 0;
}

