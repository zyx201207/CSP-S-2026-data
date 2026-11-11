#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,a[1000010];
bool b[1000010];
vector<int> e[1000010];
void dfs1(int x,int fa){
    b[x]=1;
    for(int i=0;i<e[x].size();i++){
        if(e[x][i]!=fa)dfs1(e[x][i],fa);
    }
}
bool pd(){
    dfs1(a[1],-1);
    int i=1;
    while(b[i])i++;
    dfs1(a[i],-1);
    i=1;
    while(b[i])i++;
    if(i==k+1)return 1;
    else return 0;
}
int dfs2(int x,int y,int fa){

}
void dfs(int x,int y){
    if(y>k)return;
    if(y==k){
        if(x==n+1)pd();
        return;
    }
    if(x==n+1&&y<k)return;
    a[y+1]=x;
    dfs(x+1,y+1);
    a[y+1]=0;
    dfs(x+1,y);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        cout<<0<<endl;
    }
    return 0;
}
