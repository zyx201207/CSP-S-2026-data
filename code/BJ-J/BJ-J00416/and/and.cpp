#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
void dfs(int step,int sel,int sum)
{
    if(sel==m)
    {
        ans=max(ans,sum);
        return;
    }
    if(sel>m||step>n-m+sel+1) return;
    dfs(step+1,sel+1,sum&a[step]);
    dfs(step+1,sel,sum);
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
    dfs(1,0,2147483647);
    cout<<ans<<endl;
    return 0;
}
