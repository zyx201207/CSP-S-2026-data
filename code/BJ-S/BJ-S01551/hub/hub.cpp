#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int> v[1000010];
int a[1000010],ans=1e9,d[1000010],fa[1000010];
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    while(d[x]>d[y]){
        x=fa[x];
    }
    while(x!=y){
        x=fa[x],y=fa[y];
    }
    return x;
}
int dfs2(int x,int pre){
    //cout<<x<<endl;
    fa[x]=pre;
    d[x]=d[pre]+1;
    int cnt=a[x];
    for(int i:v[x]){
        if(i==pre)continue;
        if(a[x]==0){
            cnt+=dfs2(i,x)+(a[i]==1);
        }else{
            cnt+=dfs2(i,x);
        }
    }
    return cnt;
}
bool check(){
    return dfs2(1,0)<=2;
}
void solve(){
    //if(a[1]==0 && a[2]==1 && a[3]==0 && a[4]==1 && a[5]==0)cout<<check()<<endl;
    if(check()==0)return;
    int ma=0;
    for(int i=1; i<=n; i++){
        if(a[i]==0){
            int mi=1e9;
            for(int j=1; j<=n; j++){
                if(a[j]==1){
                    int x=lca(i,j);
                    mi=min(mi,d[i]+d[j]-d[x]-d[x]);
                }
            }
            ma=max(ma,mi);
        }
    }
    ans=min(ans,ma);
}
void dfs(int step,int sum){
    if(step>n){
        solve();
        return;
    }
    a[step]=0;
    dfs(step+1,sum);
    if(sum<k){
        a[step]=1;
        dfs(step+1,sum+1);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(a,0,sizeof a);
        memset(d,0,sizeof d);
        memset(fa,0,sizeof fa);
        for(int i=1; i<=n; i++){
            v[i].clear();
        }
        ans=1e9;
        cin>>n>>k;
        for(int i=1; i<n; i++){
            int u,vv;
            cin>>u>>vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
        }
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
