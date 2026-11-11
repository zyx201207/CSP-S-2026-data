#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N],maxn=-1e9;
bool vis[N]={0};
void dfs(long long i,long long k){
    if(i==n+1&&k<m){
        return ;
    }
    if(k==m){
        long long ans=LONG_LONG_MAX;
        for(long long i=1;i<=n;i++){
            if(vis[i]){
                ans&=a[i];
            }
        }
        maxn=max(maxn,ans);
        return ;
    }
    for(long long id=i;id<=n;id++){
        vis[i]=1;
        dfs(i+1,k+1);
        vis[i]=0;
        dfs(i+1,k);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0);
    cout<<maxn;
    return 0;
}
