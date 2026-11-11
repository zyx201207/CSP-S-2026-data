#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],cnt[300005],siz[300005];
bool vis[300005];
vector<int>v[300005];
void dfs(int x){
    siz[x]=cnt[x];
    for(auto d:v[x]){
        dfs(d);
        siz[x]+=siz[d];
    }
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=n;i>=1;i--){
        if(vis[a[i]]==false){
            v[a[i+1]].push_back(a[i]);
            vis[a[i]]=true;
        }
    }
    dfs(a[n]);
    for(int i=1;i<=m;i++){
        cout<<siz[i]<<" ";
    }
    return 0;
}
