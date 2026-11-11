#include<iostream>
using namespace std;
int n,m,a[200001];
long long ans;
long long dfs(int ann,int sd)
{
    long long hjh=0;
    if(sd==m) return a[ann];
    int lby=sd+1;
    for(int i=ann+1;i<=n;i++)
    {
        long long tmp=dfs(i,lby);
        long long tmmpp=a[ann];
        hjh=max(tmp&tmmpp,hjh);
    }
    return hjh;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        ans=max(dfs(i,1),ans);
    cout<<ans;
    return 0;
}
