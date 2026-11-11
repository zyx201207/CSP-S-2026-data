#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,f[15],vis[15];
vector<int> a[1005];
bool check(){
    for(int i=1;i<=n;i++) vis[i]=0;
    int st=0;
    queue<int> q;
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++){
        if(f[i]){
            st=i;
            break;
        }
    }
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int i=0;i<a[h].size();i++){
            if(!vis[a[h][i]]&&f[a[h][i]]){
                q.push(a[h][i]);
                vis[a[h][i]]=true;
            }
        }
    }
    st=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(f[i]&&!vis[i]){
            st=i;
            break;
        }
    }
    if(st==0x3f3f3f3f) return true;
    //cout<<st<<"\n\n";
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int i=0;i<a[h].size();i++){
            if(!vis[a[h][i]]&&f[a[h][i]]){
                q.push(a[h][i]);
                vis[a[h][i]]=true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(f[i]&&!vis[i]){
            return false;
        }
    }
    return true;
}
int anss(){

    int sss=0;
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){
        while(!q.empty()) q.pop();
        if(f[i]) continue;
        q.push({i,0});
        for(int j=1;j<=n;j++) vis[j]=0;
        while(!q.empty()){
            pair<int,int> h=q.front();
            q.pop();
            if(f[h.first]){
                sss=max(sss,h.second);
                break;
            }
            for(int j=0;j<a[h.first].size();j++){
                if(!vis[a[h.first][j]]){
                    q.push({a[h.first][j],h.second+1});
                    vis[a[h.first][j]]=1;
                }
            }
        }
        //cout<<i<<" "<<sss<<"\n";
    }
    return sss;
}
int dfs(int x){
    if(x>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(f[i]) cnt++;
        }
        if(cnt!=k) return 0x3f3f3f3f;
        //cout<<f[1]<<f[2]<<f[3]<<"\n";
        if(!check()) return 0x3f3f3f3f;

        return anss();
    }
    int mn=0x3f3f3f3f;
    f[x]=true;
    mn=min(mn,dfs(x+1));
    f[x]=false;
    mn=min(mn,dfs(x+1));
    //cout<<x<<" "<<mn<<"\n";
    return mn;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        cin>>n>>k;
        for(int i=1;i<=n;i++) a[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        if(n<=10){
            //cout<<n<<k<<"\n";
            cout<<dfs(1)<<"\n";
        }

    }
    return 0;
}
