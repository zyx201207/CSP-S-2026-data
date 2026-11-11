#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,dis[4005],p[4005],len,s[4005],ans;
vector<int> v[N];
bool vis[4005];
int dfs2(int x,int fa,int dep,int o){
    int w=dep;
    for(int y:v[x]){
        if(y==fa||vis[y]) continue;
        w=max(w,dfs2(y,x,dep+1,o));
    }
    if(o){
        s[0]++;
        if(dep) s[w-dep+1]--;
    }
    return w;
}
void dfs(int x,int fa){
    vis[x]=1,len++,p[len]=x;
    int d=0;
    for(int i=1;i<=len;i++){
        if(i==1||i==len) dfs2(p[i],0,0,1);
        else d=max(d,dfs2(p[i],0,0,0)+min(i-1,len-i));
    }
    for(int i=0;i<=n;i++){
        if(i) s[i]+=s[i-1];
        if(s[i]<=k&&i>=d){
            ans=min(ans,i);
            break;
        }
    }
    for(int i=0;i<=n;i++) s[i]=0;
    for(int y:v[x]){
        if(y==fa) continue;
        dis[y]=dis[x]+1;
        dfs(y,x);
    }
    vis[x]=0,len--;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int x,y; cin>>x>>y;
            v[x].push_back(y),v[y].push_back(x);
        }
        if(n>100){
            if(k==n) ans=0;
            else{
                int m=(n-1)/2+2;
                if(k>=m) ans=1;
                else ans=(m+2-k+3)/4;
            }
        }
        else{
            ans=n;
            for(int i=1;i<=n;i++){
                len=0,dis[i]=0;
                dfs(i,0);
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}