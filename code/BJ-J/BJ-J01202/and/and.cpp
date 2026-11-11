#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,a[N],ans;
void dfs(int dep,int j,ll an){
    if(dep==m){
        ans=max(ans,an);
        return;
    }
    for(int i=j+1;i<=n;i++){
        dfs(dep+1,i,(an&a[i]));
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dfs(1,i,a[i]);
    cout<<ans;
    return 0;
}
