#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxx,p,a[N],sd;
void dfs(int x,int k,int ans){
    if(x==n){
        sd=max(sd,ans&a[x]);
        return ;
    }
    if(k==m){
       sd=max(sd,ans&a[x]);
       dfs(x+1,k,ans);
       return ;
    }
    if(x==1){
        dfs(2,k+1,a[x]);
    }
    dfs(x+1,k+1,ans&a[x]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxx=max(maxx,a[i]);
        p=p&a[i];
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    if(m==n){
        cout<<p;
        return 0;
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,0);
    }
    cout<<sd;
    return 0;
}
