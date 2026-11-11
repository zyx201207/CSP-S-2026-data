#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[2000005];

int ans;
void dfs(int lp,int step,int t)
{
    if(step==1)
    {
        ans=max(ans,t);
    }
    for(int i=lp+1;i<=n;i++)
    {
        int sum=t&a[i];
        if(sum<ans)continue;
        dfs(i,step-1,sum);
    }
}
bool cmp(int a,int b)
{
    return a<b;
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
    for(int i=1;i<=n-m+1;i++)
        dfs(i,m,a[i]);
    cout<<ans;
    return 0;
}
