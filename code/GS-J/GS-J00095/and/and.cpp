#include<bits/stdc++.h>
using namespace std;

 long long a[200005],n,m,ans=-1;

void dfs(int step,long long and1,int x)
{
    if(x>=n) return;
    if(step>=m)
    {
        ans=max(ans,and1);
        return;
    }
        dfs(step+1,and1&a[x+1],x+1);
        dfs(step,and1,x+1);

}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++) dfs(1,a[i],i);
    cout<<ans;
    return 0;

}
