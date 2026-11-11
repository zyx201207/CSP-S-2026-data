#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,k=0,a[N],nxt[N],res[M];
struct node{int s,t;}p[N];
vector<int> l[M];
bool vis[N];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int len=l[i].size();
        for(int j=0;j<len;j++){
            p[++k].s=l[i][j];
            p[k].t=l[i][len-1];
        }
    }
    for(int i=1;i<=k;i++) nxt[p[i].s]=p[i].t+1;
    for(int i=1;i<=n;i++) if(!nxt[i]) nxt[i]=i+1;
    // for(int i=1;i<=n;i++) cout<<nxt[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++){
        // cout<<i<<"\n";
        for(int j=i;j<=n;j=nxt[j]){
            // cout<<j<<":"<<a[j]<<" ";
            res[a[j]]++;
        }
        // cout<<"\n";
    }
    for(int i=1;i<=m;i++){
        if(i==m) cout<<res[i]<<"\n";
        else cout<<res[i]<<" ";
    }
    return 0;
}