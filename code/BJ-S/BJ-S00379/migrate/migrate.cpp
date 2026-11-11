#include<bits/stdc++.h>
using namespace std;
int a[2000010],ans=0;
void bfs(int u,int v,int n,int d){
    queue<pair<int,int>> q;
    vector<int> ret;
    q.push({u,0});
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=cur.first+1;i<=v;i++){
            if(a[i]>d+a[cur.first]) break;
            if(i==v){
                ret.push_back(cur.second);
                break;
            }
            q.push({i,cur.second+1});
        }
    }
    sort(ret.begin(),ret.end());
    if((ret[0]==ret[1])&&(ret[1]!=ret[2])) ans++;
    return ;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        int n,d;cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                bfs(i,j,n,d);
            }
        }
        cout<<ans<<"\n";
        memset(a,0,sizeof(a));
    }
    return 0;
}
