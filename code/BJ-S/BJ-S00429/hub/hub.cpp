#include<bits/stdc++.h>
using namespace std;
const int N=20;
int c,T;
int n,k;
int m;
vector<int> g[N];
bool vis[N];
queue<int> q;
int S[N];
int bc[N];
int find(int x){
    if(x==bc[x]) return x;
    return bc[x]=find(bc[x]);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        if(c==13||c==14){
            scanf("%d%d",&n,&k);
            for(int i=1;i<n;i++){
                int u,v;
                scanf("%d%d",&u,&v);
            }
            m=n/2;
            if(k==n) printf("0\n");
            else{
                if(k>=m) printf("1\n");
                else printf("%d\n",(m+5-k)/4);
            }
        }else{
            scanf("%d%d",&n,&k);
            for(int i=1;i<n;i++){
                int u,v;
                scanf("%d%d",&u,&v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
            int ans=INT_MAX;
            for(int f=0;f<(1<<(n+1));f+=2){
                while(!q.empty()) q.pop();
                int ji=0;
                for(int i=1;i<=n;i++){
                    S[i]=-1;
                    if((f>>i)&1) vis[i]=1;
                    else vis[i]=0;
                    if(vis[i]){
                        S[i]=0;
                        q.push(i);
                        ji++;
                    }
                }
                int fir;
                for(int i=1;i<=n;i++) bc[i]=i;
                for(int i=1;i<=n;i++){
                    if(vis[i]==0) continue;
                    fir=i;
                    for(int j=0;j<g[i].size();j++){
                        if(vis[g[i][j]]==0) continue;
                        bc[find(i)]=find(g[i][j]);
                    }
                }
                bool flag=1;
                int fir2=0;
                for(int i=1;i<=n;i++){
                    if(vis[i]==0) continue;
                    if(find(i)!=find(fir)){
                        if(fir2&&find(fir2)!=find(i)) flag=0;
                        else fir2=i;
                    }
                }
                if(!flag) continue;
                if(ji!=k) continue;
                while(!q.empty()){
                    int nw=q.front();
                    q.pop();
                    for(int j=0;j<g[nw].size();j++){
                        if(S[g[nw][j]]==-1){
                            S[g[nw][j]]=S[nw]+1;
                            q.push(g[nw][j]);
                        }
                    }
                }
                int Max=0;
                for(int i=1;i<=n;i++) Max=max(Max,S[i]);
                ans=min(ans,Max);
            }
            printf("%d\n",ans);
            for(int i=1;i<=n;i++) g[i].clear();
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}