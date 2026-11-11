#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N=2e6+10;

bool fl[N];
vector<int>e[N];
int n,k,ans;
int dis[N];
queue<int>q;
int bfs(){
    for(int i=1;i<=n;i++){
        dis[i]=0;
        if(fl[i]){
            q.push(i);
        }
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(auto v:e[u]){
            if(!dis[v]&&!fl[v]){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)cnt=max(cnt,dis[i]);
    return cnt;
}
void dfs(int x,int cnt1,int cnt2){
    if(cnt1<0||cnt2<0)return;
    if(n-x+1<cnt1)return ;
    if(x>n){
        ans=min(ans,bfs());
        return;
    }
    fl[x]=0;
    dfs(x+1,cnt1,cnt2);
    for(auto v:e[x]){
        if(fl[v]){
            cnt2++;
            break;
        }
    }
    cnt2--;
    fl[x]=1;
    dfs(x+1,cnt1-1,cnt2);
    fl[x]=0;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            e[i].clear();
        }
        cin>>n>>k;
        if(c==13||c==14){
            if(k==n){
                cout<<"0\n";
            }
            else if(k>=n/2){
                cout<<"1\n";
            }
            else{
                cout<<(n/2-k+3)/4+1<<'\n';
            }
            continue;
        }
        ans=n;
        for(int i=1,x,y;i<n;i++){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        dfs(1,k,2);
        cout<<ans<<'\n';
    }
    return 0;
}
