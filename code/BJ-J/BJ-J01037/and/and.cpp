#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],vis[200001],ans;
void dfs(int x,int num)
{
    if(num==m)
    {
        int sum=vis[1];
        for(int i=1;i<=num;i++)
        {
            sum=sum&vis[i];
        }
        ans=max(ans,sum);
        return;
    }
    for(int i=x+1;i<=n;i++)
    {
        vis[num+1]=a[i];
        dfs(i,num+1);
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++)
        {
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    dfs(0,0);
    cout<<ans;
	return 0;
}
