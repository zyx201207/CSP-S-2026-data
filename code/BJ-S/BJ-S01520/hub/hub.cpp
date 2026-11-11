#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int N=1000005,SN=4005;

int n,k,d;
vector<int> g[N];
int ans;

int depth[N];
void getdepth(int u,int cfa){
    depth[u]=depth[cfa]+1;
    for(auto x:g[u]){
        if(x==cfa) continue;
        getdepth(x,u);
    }
}

int fa[N];
void initdsu(int n){
    for(int i=1;i<=n;++i){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    a=find(a);b=find(b);
    if(a==b) return ;
    fa[a]=b;
}

bool chosen[N],valid[N];
int dis[SN][SN];
int cnt=0,vcnt=0;
void dfs(int u){
    if(u>n){
        if(cnt!=k) return ;
        int cans=0;
        initdsu(n);
        for(int i=1;i<=n;++i){
            for(auto x:g[i]){
                if(chosen[i] && chosen[x]){
                    merge(i,x);
                }
            }
        }int c1=0,c2=0;
        for(int i=1;i<=n;++i){
            if(chosen[i]){
                if(find(i)!=c1){
                    if(!c1) c1=find(i);
                    else if(find(i)!=c2){
                        if(!c2) c2=find(i);
                        else return ;
                    }
                }
            }
        }
        for(int i=1;i<=n;++i){
            int ccans=n;
            for(int j=1;j<=n;++j){
                if(chosen[j]){
                    ccans=min(ccans,dis[i][j]);
                }
            }cans=max(ccans,cans);
            //if(chosen[2] && chosen[4]) cout<<cans<<' ';
        }//cout<<'\n';
        ans=min(ans,cans);
        return ;
    }
    dfs(u+1);
    if(cnt<k){
        ++cnt;
        chosen[u]=true;
        dfs(u+1);
        chosen[u]=false;
        --cnt;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if(c==13 || c==14){
            if(k==n){
                cout<<"0\n";
            }else{
                int b=(n+1)/2+4-k;
                cout<<b/4+bool(b%4)<<"\n";
            }continue;
        }
        for(int i=1;i<=n;++i){
            getdepth(i,0);
            for(int j=1;j<=n;++j){
                dis[i][j]=depth[j]-1;
            }
        }//cout<<"gree"<<endl;
        ans=n;
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
