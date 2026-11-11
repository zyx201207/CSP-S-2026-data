#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+5;
const int N=505;
int c,n,m,d,q;
int cnt[M];
bool vis[M][25];
struct station{
    int w,t[25];
}s[M];
struct side{
    int u1,u2,val;
    bool operator < (const side &x) const{
        return x.val<val;
    }
};
vector<side> v[M][25];
int bfs(int x,int y){
    priority_queue<side> q;
    q.push({x,0,0});
    vis[x][0]=1;
    while(!q.empty()){
        side now=q.top();
        q.pop();
        if(now.u1==y&&now.u2==0) return now.val;
        for(auto it:v[now.u1][now.u2]){
            if(!vis[it.u1][it.u2]){
                q.push({it.u1,it.u2,now.val+it.val});
                vis[it.u1][it.u2]=1;
            }
        }
    }
    return -1;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        int x;cin>>x;
        v[i][0].push_back({i,1,x});
        v[i][1].push_back({i,0,x});
    }
    for(int i=1;i<=n;i++){
        int num,pre,x,y;
        cin>>num;
        for(int j=1;j<=num;j++){
            cin>>x>>y;
            v[x][1].push_back({x,(++cnt[x])+1,y});
            v[x][cnt[x]+1].push_back({x,1,y});
            if(j>1){
                v[x][cnt[x]+1].push_back({pre,cnt[pre]+1,(long long)(0)});
                v[pre][cnt[pre]+1].push_back({x,cnt[x]+1,(long long)(0)});
            }
            pre=x;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(vis));
        cout<<bfs(x,y)<<"\n";
    }
    return 0;
}
