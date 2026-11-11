#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],cnt;
bool vis[2000005];
struct N{
    int x,w;
}w[2000005];
int bfs(int s){
    int cnt=0;
    queue<N>q;
    q.push({s,0});
    while(!q.empty()){
        N p=q.front();
        q.pop();
        if(w[p.x].x==0||w[p.x].w==p.w){
            w[p.x].x++;
            w[p.x].w=p.w;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]&&abs(x[i]-x[p.x])<=d){
                vis[i]=1;
                q.push({i,p.w+1});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(w[i].x==2)cnt++;
    }
    return cnt;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            if(x[2]-x[1]>=d)cout<<"0\n";
            else{
                cout<<max(0ll,n-2*d/(x[2]-x[1])+1)<<"\n";
            }
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<bfs(1)<<"\n";
    }
    return 0;
}
