#include<bits/stdc++.h>
using namespace std;
int a[500010],nxt[300010],ans[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) flag=false;
    }
    if(flag)
    {
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
        cout<<'\n';
        return 0;
    }
    for(int j=1;j<=n;j++) nxt[a[j]]=j;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            if(nxt[a[j]]) j=nxt[a[j]];
            ans[a[j]]++;
        }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}
