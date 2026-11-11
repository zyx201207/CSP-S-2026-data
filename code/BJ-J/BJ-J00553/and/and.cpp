#include<bits/stdc++.h>
using namespace std;
long long a[200010];
bool vis[200010];
long long n,m;
vector<long long> pick;
long long ans=0;
long long calc()
{
    long long ans=pick[0];
    for(int num:pick)
    {
        ans&=num;
    }
    return ans;
}
void dfs(int dep)
{
    if(dep==m)
    {
        ans=max(ans,calc());
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        pick.push_back(a[i]);
        vis[i]=true;
        dfs(dep+1);
        vis[i]=false;
        pick.pop_back();
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0);
    cout<<ans;
    return 0;
}
