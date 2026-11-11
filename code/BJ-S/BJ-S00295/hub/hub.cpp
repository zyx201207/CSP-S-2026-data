#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=20;
int c,T,n,k,u[N],v[N],fa[N],dis[N][N];
vector<int> g[N];

int getfa(int x){
    if(fa[x]==x) return x;
    else return fa[x]=getfa(fa[x]);
}
void merge(int u,int v){
    fa[getfa(u)]=getfa(v);
}
void dfs(int u,int fa,int st){
    for(int v:g[u]){
        if(v==fa) continue;
        dis[v][st]=dis[u][st]+1;
        dfs(v,u,st);
    }
}
signed main(){

    cin>>c>>T;
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    if(c<=3){
    while(T--){
        cin>>n>>k;
        int ans=1e9;
        for(int i=1;i<n;i++){
             cin>>u[i]>>v[i];
             g[u[i]].push_back(v[i]);
             g[v[i]].push_back(u[i]);
        }

        for(int s=1;s<(1<<n);s++){
            int a[N],x=s,tot=0;
            for(int i=1;i<=n;i++) a[i]=0,fa[i]=i;
            for(int i=1;i<=n-1;i++){
                if(x%2==1){
                        if(!a[u[i]]) a[u[i]]=1,tot++;
                        if(!a[v[i]]) a[v[i]]=1,tot++;
                        merge(u[i],v[i]);
                }
                x/=2;
            }
            if(tot!=k) continue;
            set<int> st;
            st.clear();
            for(int i=1;i<=n;i++){
                if(!a[i]) continue;
                int g=getfa(i);
                st.insert(g);
            }
            if(st.size()>2) continue;
            for(int i=1;i<=n;i++){
                dis[i][i]=0;
                dfs(i,0,i);
            }
            int minn[N],maxx=0;
            for(int i=1;i<=n;i++){
                minn[i]=1e9;
                for(int j=1;j<=n;j++){
                    if(!a[i]&&a[j]){
                        minn[i]=min(minn[i],dis[i][j]);
                    }
                }
                if(!a[i]) maxx=max(minn[i],maxx);
            }
            ans=min(ans,maxx);

        }
        cout<<ans<<"\n";

   }
   }
}
