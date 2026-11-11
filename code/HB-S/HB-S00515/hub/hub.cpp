#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
vector<int> G[N];
int d[N];
int tmp[N];
int fa[N];
bool vis[N];
int dot1,dot2;
int cnt[2];
bool bl[N];
int n,k;
int diss[N];

int far,maxdis;

void dfs(int x,int dis){
    vis[x]=1;
    //cout<<x<<" "<<dis<<'\n';
    if(dis>maxdis){
        maxdis=dis;
        far=x;
    }
    for(int y:G[x]){
        if(!vis[y]){
            dfs(y,dis+1);
        }
    }
}

void dfs2(int x,int dis){
    vis[x]=1;
    diss[x]=dis;
    if(dis>maxdis){
        maxdis=dis;
        far=x;
    }
    for(int y:G[x]){
        if(!vis[y]){
            fa[y]=x;
            dfs2(y,dis+1);
        }
    }
}

void findc(){
    memset(vis,0,sizeof(vis));
    maxdis=0;
    dfs(1,0);
    //cout<<"ok"<<'\n';
    //cout<<far<<'\n';
    memset(vis,0,sizeof(vis));
    maxdis=0;
    dfs2(far,0);
    int k=(maxdis+1)/2;
    //cout<<k<<'\n';
    int noww=far;
    while(diss[noww]>k){
        //cout<<noww<<" "<<diss[noww]<<'\n';
       noww=fa[noww];
    }
    dot1=noww;
    dot2=fa[noww];
}

void dfs3(int x,int f,int ps){
    bl[x]=1;
    cnt[1]++;
    for(int y:G[x]){
       if(y==f||y==ps){
           continue;
       }
       dfs3(y,x,ps);
    }
}

int check(int u,int v){
    memset(bl,0,sizeof(bl));
    cnt[1]=0;
    dfs3(v,0,u);
    cnt[0]=n-cnt[1];
    cout<<cnt[0]<<" "<<cnt[1]<<'\n';
    int num=0;
    int rst=n;
    while(rst>k){
        num++;
        //cout<<rst<<" "<<'\n';
        for(int i=1;i<=n;i++){
            if(d[i]==1&&cnt[bl[i]]!=1){
                for(int y:G[i]){
                    d[y]--;
                }
                rst--;
                cnt[bl[i]]--;
            }
        }
    }
    return num;
}

void clr(int n){
    for(int i=1;i<=n;i++){
        G[i].clear();
        d[i]=0;
        fa[i]=0;
        diss[i]=0;
    }
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   freopen("hub.in","r",stdin);
   freopen("hub.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--){
       cin>>n>>k;
       //cout<<"******"<<n<<" "<<k<<'\n';
       for(int i=1;i<n;i++){
           //cout<<i<<" "<<n<<'\n';
           int u,v;
           cin>>u>>v;
           G[u].push_back(v);
           G[v].push_back(u);
           d[u]++;
           d[v]++;
           //cout<<"ok"<<'\n';
       }
       
       findc();
       //cout<<dot1<<" "<<dot2<<" "<<far<<" "<<maxdis<<'\n';
       int res=n;
       for(int v:G[dot1]){
           res=min(res,check(v,dot1));
       }
       for(int v:G[dot2]){
           res=min(res,check(v,dot2));
       }
       cout<<res<<'\n';

     clr(n);
   }
    return 0;
}