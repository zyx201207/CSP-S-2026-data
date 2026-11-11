#include <iostream>
#include <vector>
using namespace std;

int n,m;
int a[500010];
vector<int> edge[300010];
int b[300010];
int sz[500010];
int nxt[300010];

void dfs(int p){
    sz[p]=1;
    for(int v:edge[p]){
        dfs(v);
        sz[p]+=sz[v];
    }
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(nxt[a[i]]==0){
            b[a[i]]=i;
            edge[i+1].push_back(i);
        }else{
            edge[nxt[a[i]]].push_back(i);
        }
        nxt[a[i]]=i;
    }
    dfs(n);
    for(int i=1;i<=m;i++){
        cout<<sz[b[i]]<<' ';
    }
    return 0;
}