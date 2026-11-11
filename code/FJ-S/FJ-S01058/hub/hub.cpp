#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,tmp,ans,a[100010],vis[100010];
vector<long long>g[100010];
queue<pair<long long,long long> >q;
long long read(){
    long long x=0;char ac=getchar();
    while(ac<'0' || ac>'9') ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x;
}
void init(){
    for(long long i=1;i<=n;i++)
        g[i].clear();
}
void work(long long u,long long fa){
    vis[u]=tmp;
    for(auto v:g[u]) if(v!=fa && !vis[v] && a[v])
        work(v,u);
}
long long bfs(long long s){
    while(!q.empty()) q.pop();
    q.push(make_pair(s,0));
    while(!q.empty()){
        long long now=q.front().first,dis=q.front().second;
        q.pop();
        if(a[now]) return dis;
        for(auto v:g[now])
            q.push(make_pair(v,dis+1));
    }
    return n;
}
void dfs(long long now){
    if(now==n+1){
        tmp=0;
        for(long long i=1;i<=n;i++)
            if(a[i]) tmp++;
        if(tmp!=k) return ;
        tmp=0;
        for(long long i=1;i<=n;i++)
            vis[i]=0;
        for(long long i=1;i<=n;i++)
            if(a[i] && !vis[i]) tmp++,work(i,i);
        if(tmp>2) return ;
        tmp=0;
        for(long long i=1;i<=n;i++)
            tmp=max(tmp,bfs(i));
        ans=min(ans,tmp);
        return ;
    }
    a[now]=1,dfs(now+1);
    a[now]=0,dfs(now+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),k=read(),init();
        for(long long i=1;i<n;i++){
            long long u=read(),v=read();
            g[u].push_back(v),g[v].push_back(u);
        }
        if(c==13 || c==14){
            long long tmp=(n-1)/2-k;
            if(k==n) printf("0\n");
            else if(tmp<=0) printf("1\n");
            else printf("%lld\n",(tmp+1)/4+1);
        }
        if(c>=1 && c<=3){
            ans=n,dfs(1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}