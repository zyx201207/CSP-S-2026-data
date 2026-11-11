#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
int ans,maxx=0;
void dfs(int jl,int pa,int step){
    if(step==m){
        ans=max(ans,jl);
        return;
    }
    if(n-pa<m-step){
        return;
    }
    for(int i=pa+1;i<=n;i++){
        dfs(jl&a[i],i,step+1);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=2000){
        for(int i=1;i<=n;i++){
            dfs(a[i],i,1);
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    return 0;
}
