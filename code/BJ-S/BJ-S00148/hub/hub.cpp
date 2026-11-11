#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
#define mid ((l+r)>>1)
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+6;
int n,k,ans,Fa[N],dis[N],dep[N];
vector<int>v[N];
void getdis(int x,int fa,int c){
    Fa[x]=fa;
    for(int i:v[x]){
        if(i==fa || i==c)continue;
        dis[i]=dis[x]+1;
        getdis(i,x,c);
    }
    dep[x]=dis[x];
    for(int i:v[x]){
        if(i==fa || i==c)continue;
        dis[x]=max(dis[i],dis[x]);
    }
}
int dfs(int x,int fa,int la){
    int cnt=0,ma=0;
    int id=0;
    for(int i:v[x]){
        if(i==fa)continue;
        if(dis[i]==dis[x]){
            cnt++,id=i;
        }
        if(dis[i]<dis[x])ma=max(dis[i]-dep[x],ma);
    }
    if(cnt==1 && max(la+1,ma+1)<=dis[x]-dep[x]-1){
        return dfs(id,x,max(la+1,ma+1));
    }else return x;
}
int get(int x,int y){
    dis[x]=dis[y]=0;
    getdis(x,y,0);
    getdis(y,x,0);
    int rt=dfs(x,y,0);
    int rt2=dfs(y,x,0);
    dis[rt]=dis[rt2]=0;
    getdis(rt,0,y);
    getdis(rt2,0,x);
    int cnt=2;
    priority_queue<pii >q,q2;
    for(int i:v[rt]){
        if(i==y)continue;
        q.push({dis[i]-dep[i],i});
    }
    for(int i:v[rt2]){
        if(i==x)continue;
        q2.push({dis[i]-dep[i],i});
    }
    while(cnt<k && (!q.empty() || !q2.empty())){
        if(!q.empty() && (q2.empty() || q.top().fi>=q2.top().fi)){
            int x=q.top().se;
            q.pop();
            for(int i:v[x]){
                if(i==Fa[x] || i==y)continue;
                q.push({dis[i]-dep[i],i});
            }
        }else {
            int x=q2.top().se;
            q2.pop();
            for(int i:v[x]){
                if(i==Fa[x] || i==x)continue;
                q2.push({dis[i]-dep[i],i});
            }
        }
        cnt++;
    }
    if(q.empty() && q2.empty())return 0;
    if(q.empty() || q2.empty()){
        if(q.empty())return q2.top().fi+1;
        else return q.top().fi+1;
    }
    return max(q.top().fi,q2.top().fi)+1;
}
void check(int x,int fa){
    for(int i:v[x]){
        if(i==fa)continue;
        int now=get(x,i);
        ans=min(now,ans);
        check(i,x);
    }
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int s,e;cin>>s>>e;
        v[s].pb(e);
        v[e].pb(s);
    }
    int st=(10231039%n+1);
    ans=1e9;
    check(st,0);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++){
        v[i].clear();
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int AC65,T;cin>>AC65>>T;
    while(T--){
        solve();
    }
    return 0;
}