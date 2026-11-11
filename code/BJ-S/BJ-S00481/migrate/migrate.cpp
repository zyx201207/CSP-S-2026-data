#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e3+5;
int n,c,t,d,x[MAXN],dis[MAXN][MAXN],doub[MAXN][MAXN];
void BFS(int node,vector<int> ed[MAXN]){
    queue<int> que;
    que.push(node);
    while(!que.empty()){
        int no=que.front();
        que.pop();
        for(int i=0;i<ed[no].size();i++){
            if(!dis[node][ed[no][i]]){
                que.push(ed[no][i]);
                dis[node][ed[no][i]]=dis[node][no]+1;
            }
            else if(dis[node][ed[no][i]]==dis[node][no]+1){
                doub[node][ed[no][i]]++;
            }
        }
    }
    return ;
}
void slove(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        x[i]=0;
        for(int j=0;j<n;j++){
            dis[i][j]=0;
            doub[i][j]=0;
        }
    }
    vector<int> ed[MAXN];
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]-x[j]<=d&&x[j]-x[i]<=d){
                ed[i].push_back(j);
                ed[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        BFS(i,ed);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(doub[i][j]==1){
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){

        slove();
    }
    return 0;
}
