#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL C,t,n,k;
vector<LL> c[2000010];
LL deep[2000010];
LL u,v;
bool vis[2000010];
struct str{
    LL v,d;
    /*
    bool operator < (const str &rsh) const{
        return d>rsh.d;
    }
    */
}N;
//priority_queue<str,vector<str>,greater<str> > q;
void dfs(LL x,LL cnt){
    deep[x]=cnt;
    for(int i=0;i<c[x].size();i++){
        if(cnt+1<deep[c[x][i]]){
            dfs(c[x][i],cnt+1);
        }
    }
}
void dfs1(LL x){
    vis[x]=0;
    for(int i=0;i<c[x].size();i++){
        if(vis[c[x][i]]){
            dfs1(c[x][i]);
        }
    }
}
bool check(LL x){
    while(!q.empty()) q.pop();
    LL kk=k;
    for(int i=1;i<=n;i++){
        if(deep[i]%(2*x)==x){
            vis[i]++;
            kk--;
            N.v=i;
            N.d=deep[i];
            q.push(N);
        }
    }
    for(int i=1;i<=n;i++){
        bool f=1;
        for(int j=0;j<c[i].size();j++){
            if(deep[c[i][j]]>deep[i]){
                f=0;
                break;
            }
        }
        if(f&&deep[i]%(2*x)>x){
            vis[i]++;
            kk--;
            N.v=i;
            N.d=deep[i];
            q.push(N);
        }
    }
    if(kk<0) return 0;
    return 1;
    /*
    memset(deep,0x3f,sizeof(deep));
    for(int i=1;i<=n;i++){
        if(vis[i]){
            dfs(i,0);
        }
    }
    for(int i=1;i<=n&&kk!=0;i++){
        u=0;
        for(int j=0;j<c[i].size();j++){
            if(deep[c[i][j]]<deep[i]){
                u++;
            }
        }
        if(u>=2){
            q.push({i,deep[i]});
        }
    }
    while(!q.empty()&&kk!=0){
        N=q.top();
        q.pop();
        if(N.d>kk) break;
        kk-=N.d;
        dfs(N.v,0);
    }
    u=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            u++;
            dfs1(i);
        }
    }
    return u<=2;
    */
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&C,&t);
    while(t--){
        memset(deep,0x3f,sizeof(deep));
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n-1;i++){
            scanf("%lld%lld",&u,&v);
            c[u].push_back(v);
            c[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(c[i].empty()){
                dfs(i,0);
            }
        }
        LL l=1,r=n+1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
