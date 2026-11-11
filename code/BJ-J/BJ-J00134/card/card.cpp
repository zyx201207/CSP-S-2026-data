#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],nxt[N];
int t[N];
int sz[N];
int ans[N];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        if(!t[a[i]])nxt[i]=n+1;
        else nxt[i]=t[a[i]];
        t[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        sz[i]++;
        if(nxt[i]!=n+1) sz[nxt[i]]+=sz[i];
        else 
        {
            // sz[i]+=sz[i-1];
            sz[i+1]+=sz[i];
            ans[a[i]]=sz[i];
        }
    }
    // for(int i=1;i<=n;i++) cout<<sz[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
