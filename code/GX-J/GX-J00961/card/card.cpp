#include <bits/stdc++.h>

#define c(x) cout<<x<<endl
#define inf 0x3f3f3f3f
#define fet(x) const int fet=x;

using namespace std;

fet(5e5);
int n,m,a[fet];

int last[fet];
int f[fet];
int ans[fet];

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=fet;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i;i--){
        if(last[a[i]]) f[i]=last[a[i]];
        else last[a[i]]=i;
    }
    vector<int> v;
    for(int stra=1;stra<=n;stra++){
        v.clear();
        bool vis[m+10];
        memset(vis,0,sizeof(vis));
        for(int i=stra;i<=n;i++){
            v.push_back(a[i]);
            i=f[i];
        }
        for(int i=0;i<v.size();i++)
            vis[v[i]]=true;
        for(int i=1;i<=m;i++)
            if(vis[i]) ans[i]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
