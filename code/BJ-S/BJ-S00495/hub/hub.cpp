#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,u,v,st,ans,kk,f[1000005],mx;
bool vs[1000005];
vector<int> ve[1000005];
inline int dfs(int dq,int ff,int sg){
    int xg=1e9;
    for(auto it:ve[dq]){
        if(it==ff){
            continue;
        }
        if(vs[dq]){
            xg=dfs(it,dq,0)+1;
        }else{
            xg=dfs(it,dq,sg+1)+1;
            if(xg<1e8){
                mx=max(mx,(sg+1+xg)/2);
            }else{
                mx=max(mx,sg+1);
            }
        }
    }
    if(vs[dq]){
        return 0;
    }return xg;
}
inline void sv(){
    ans=1e9;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        ve[i].clear();
    }
    for(int i=1;i<n;i++){
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for(int i=1;i<(1<<n);i++){
        kk=mx=0;
        memset(vs,0,sizeof(vs));
        for(int j=1;j<=n;j++){
            if(i&(1<<(j-1))){
                kk++;
                vs[j]=1;
                st=j;
            }
        }
        if(kk>k){
            continue;
        }
        dfs(st,0,0);
        ans=min(ans,mx);
    }
    cout << ans << "\n";
    return;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin >> c >> t;
    while(t--){
        sv();
    }
    return 0;
}
