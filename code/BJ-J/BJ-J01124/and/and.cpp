#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int maxn=200005;

int n,m,a[maxn],ans;
void dfs(int x,int cnt,int sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=x+1;i<=n;i++){
        if(cnt==0) dfs(i,cnt+1,a[i]);
        else dfs(i,cnt+1,sum&a[i]);
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
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
