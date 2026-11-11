#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T;
int n,d;
int x[2000010];
struct node{
    int p,s;
};
bool f[2000010];
bool bfs(int u,int v){
    memset(f,0,sizeof f);
    queue<node> q;
    q.push({u,0});
    int pos=0x3f3f3f3f3f3f3f3f,cnt=0;
    while(q.size()){
        node t=q.front();q.pop();
        if(t.p==v){
            pos=t.s;
            break;
        }else{
            for(int i=t.p+1;x[t.p]+d>=x[i];i++){
                if(f[x[i]]) continue;
                f[x[i]]=1;
                q.push({x[i],t.s+1});
            }
        }
    }
    while(q.size()) q.pop();
    q.push({u,0});
    while(q.size()){
        node t=q.front();q.pop();
        if(t.p==v&&t.s==pos){
            cnt++;
        }else{
            if(t.s>=pos) continue;
            for(int i=t.p+1;x[t.p]+d>=x[i];i++){
                q.push({x[i],t.s+1});
            }
        }
    }
    return cnt==2;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(bfs(i,j)) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
