#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int dfs(int k,int sa,int o)
{
    if(k==m+1)
    {
//        cout<<k<<" "<<sa<<" "<<o<<endl;
        return sa;
    }
    int sm=0;
    for(int i=o+1;i<=n;i++)
    {
        if(k==1) sm=max(dfs(k+1,a[i],i),sm);
        else sm=max(dfs(k+1,sa&a[i],i),sm);
    }
    return sm;
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
    cout<<dfs(1,0,0);
    return 0;
}
