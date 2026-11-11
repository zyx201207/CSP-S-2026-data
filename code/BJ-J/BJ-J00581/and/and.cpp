#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int box[N];
int a[N];
bool vis[N];
int n,m;
int maxx=INT_MIN;
void dfs(int k,int c){
    if(c<maxx){
        return;
    }
    if(k==m+1){
        maxx=c;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            box[k]=i;
            dfs(k+1,c&a[i]);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,INT_MAX);
    cout<<maxx;
    return 0;
}
