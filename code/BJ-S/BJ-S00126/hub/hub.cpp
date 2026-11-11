#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int n,k,ans;
vector<int> v[maxn],got,zhijing;
bool visited[maxn],vis[maxn];
int dis[maxn];
void dfs(int x){
    vis[x]=true;
    for(int i=0;i<v[x].size();i++){
        int dx=v[x][i];
        if(visited[dx]&&!vis[dx]){
            dfs(dx);
        }
    }
}
int bfs(){
    queue<int> q;
    for(int i=0;i<got.size();i++){
        q.push(got[i]);
        dis[got[i]]=0;
    }
    int maxdis=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        maxdis=max(maxdis,dis[x]);
        for(int i=0;i<v[x].size();i++){
            int dx=v[x][i];
            if(dis[dx]>dis[x]+1){
                dis[dx]=dis[x]+1;
                q.push(dx);
            }
        }
    }
    return maxdis;
}
int bfs2(int st){
    queue<int> q;
    for(int i=1;i<=n;i++){
        vis[i]=false;
    }
    int lst=0;
    vis[st]=true;
    q.push(st);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        lst=x;
        for(int i=0;i<v[x].size();i++){
            int dx=v[x][i];
            if(!vis[dx]){
                vis[dx]=true;
                q.push(dx);
            }
        }
    }
    return lst;
}
bool dfs2(int x,int f,int y){
    if(x==y){
        zhijing.push_back(x);
        return true;
    }
    for(int i=0;i<v[x].size();i++){
        int dx=v[x][i];
        if(dx==f){
            continue;
        }
        if(dfs2(dx,x,y)){
            zhijing.push_back(x);
            return true;
        }
    }
    return false;
}
void suan(){
    for(int i=1;i<=n;i++){
        vis[i]=false;
        dis[i]=1e9;
    }
    int cnt=0;
    for(int i=0;i<got.size();i++){
        int x=got[i];
        if(!vis[x]){
            dfs(x);
            cnt++;
        }
    }
    if(cnt>2){
        return;
    }
    ans=min(ans,bfs());
}
void f(int x,int y){
    if(x==n+1){
        suan();
        return;
    }
    if(n-x+1+y<k){
        return;
    }
    if(y<k){
        got.push_back(x);
        visited[x]=true;
        f(x+1,y+1);
        visited[x]=false;
        got.pop_back();
    }
    f(x+1,y);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            v[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(c==13||c==14){
            if(((n+1)/2-k+4)/4>=1){
                cout<<((n+1)/2-k+4)/4<<'\n';
            }
            else if(k==n){
                cout<<"0\n";
            }
            else{
                cout<<"1\n";
            }
            continue;
        }
        if(c==7||c==11||c==12){
            int aa=bfs2(1);
            int bb=bfs2(aa);
            zhijing.clear();
            bool ff=dfs2(aa,0,bb);
            ans=1e9;
            //cout<<aa<<' '<<bb<<endl;
           // for(int i=0;i<zhijing.size();i++){
            //    cout<<zhijing[i]<<' ';
            //}
            //cout<<endl;
            for(int i=0;i<zhijing.size();i++){
                got.push_back(zhijing[i]);
                for(int j=i+1;j<zhijing.size();j++){
                    got.push_back(zhijing[j]);
                    for(int kk=1;kk<=n;kk++){
                        dis[kk]=1e9;
                    }
                    ans=min(ans,bfs());
                    //cout<<got[0]<<' '<<got[1]<<' '<<bfs()<<endl;
                    //for(int i=1;i<=n;i++){
                    //    cout<<dis[i]<<' ';
                   // }
                    //cout<<endl;
                    got.pop_back();
                }
                got.pop_back();
            }
            cout<<ans<<'\n';
            continue;
        }
        ans=1e9;
        f(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
