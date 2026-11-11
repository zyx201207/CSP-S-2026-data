#include<bits/stdc++.h>
using namespace std;
const int NA=10,Inf=1e9,N=1000000;
struct Point{
    vector<int>edge;
}a[N+5];
bool f[NA+5],from[NA+5];
int testid,T,n,k,ans,dis[NA+5][NA+5];
void colorA(int u){
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v:a[u].edge){
            if(!from[v]&&f[v]){
                from[v]=1;
                q.push(v);
            }
        }
    }
}
inline void dfsA(int x,int use){
    if(use>k)return;
    if(x>n){
        if(use!=k)return;
        int sum=0,res=0;
        for(int i=1;i<=n;++i)from[i]=0;
        for(int i=1;i<=n;++i)if(f[i]&&from[i]==0)sum++,colorA(i);
        if(sum>2)return;
        for(int i=1;i<=n;++i){
            int now=1000000000;
            for(int j=1;j<=n;++j)if(f[j])now=min(now,dis[i][j]);
            res=max(res,now);
        }
        ans=min(ans,res);
        return;
    }
    f[x]=0;
    dfsA(x+1,use);
    f[x]=1;
    dfsA(x+1,use+1);
    f[x]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>T;
    while(T--){
        cin>>n>>k;
        ans=Inf;
        for(int i=1;i<=n;++i)a[i].edge.clear();
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=Inf;
        for(int i=1;i<=n;++i)dis[i][i]=0;
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            a[u].edge.push_back(v);
            a[v].edge.push_back(u);
            dis[u][v]=dis[v][u]=1;
        }
        for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        dfsA(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}