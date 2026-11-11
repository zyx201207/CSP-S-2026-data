#include<bits/stdc++.h>
using namespace std;
int n,m;
long long x[1000005];
long long d[1000005];
long long cnt[100005];
vector<int> a[1000005];

void ctr(){
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
}
void init(){
    for(int i=1;i<=n;i++){
        cnt[i]=0;
    }
}
void bfs(int s){
    d[s]=0;
    queue<int> q;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        int len=a[u].size();
        for(int i=0;i<=len;i++){
            int v=a[u][i];
            q.push(v);
            if(d[v]==d[u]+1){
                cnt[v]++;
            }
            else{
                d[v]=d[u]+1;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[j]-x[i]==d[i]){
                    a[i].push_back(i);
                    a[j].push_back(j);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
                init();
            bfs(i);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

