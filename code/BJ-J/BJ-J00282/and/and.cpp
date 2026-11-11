#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;

void dfs(int u,int tnt,int point){
    if(point==m){
        maxn=max(maxn,tnt);
        return;
    }
    if(u>n){
        return;
    }
    dfs(u+1,tnt,point);
    if(!tnt){
        dfs(u+1,a[u],point+1);
    }else{
        dfs(u+1,tnt&a[u],point+1);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<maxn;
    return 0;
}