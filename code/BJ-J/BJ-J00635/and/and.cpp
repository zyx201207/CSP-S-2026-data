#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ma;
void dfs(int c,int pln,int plm){
    if(plm>=m){
        ma=max(ma,c);
        return;
    }
    for(int i=pln+1;i<=n-m+plm+1;i++){
        dfs(c&a[i],i,plm+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n-m+1;i++)dfs(a[i],i,1);
    cout<<ma;
    return 0;
}
//abs(A)<abs(O)!
