#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m,a[200001];
inline void dfs(long long i,long long j,long long he){
    if(j==m){
        ans=max(ans,he);
        return;
    }
    if(i==n){
        return;
    }
    dfs(i+1,j+1,a[i]&he);
    dfs(i+1,j,he);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;++i){
        cin>>a[i];
    }
    dfs(0,0,(1ll<<31)-1);
    cout<<ans;
    return 0;
}
