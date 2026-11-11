#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
int n,m,ans;
int a[N];
void dfs(int dep,int sum,int k)
{
    if(k==m) 
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=dep+1;i<=n;i++)
    {
        dfs(i,sum&a[i],k+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        dfs(i,a[i],1);
    cout<<ans<<"\n";
    return 0;
}