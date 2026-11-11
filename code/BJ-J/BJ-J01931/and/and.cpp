#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];
int ans=0;
int n,m;
void dfs(int step,int k,int cnt)
{
    if(cnt>m)return ;
    if(step>m)
    {
        if(cnt==m)ans=max(ans,k);
        return ;
    }
    dfs(step+1,k&a[step],cnt+1);
    dfs(step+1,k,cnt);
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dfs(1,a[i],1);
    }
    sort(a+1,a+n+1,cmp);
    int v=a[1];
    for(int i=2;i<=m;i++)
    {
        v&=a[i];
    }
    cout<<v;
    return 0;
}
