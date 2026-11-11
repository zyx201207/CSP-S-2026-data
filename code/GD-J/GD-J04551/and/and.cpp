#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],vis[100000],ans,b[100000];
void dfs(int x,int pos)
{
    if(x>m)
    {
        int sum=b[1];
        for(int i=2;i<=m;i++)
        {
            sum&=b[i];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=pos;i<=n;i++)
    {
        if(vis[i]==0)
        {
            b[x]=a[i];
            vis[i]=1;
            dfs(x+1,i);
            b[x]=a[i];
            vis[i]=0;
        }
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n>2000)
    {
    	sort(a+1,a+n+1);
		long long ans=a[n];
		for(int i=n-1;i>n-m;i--)
		{
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
    dfs(1,1);
    cout<<ans;
    return 0;
}
