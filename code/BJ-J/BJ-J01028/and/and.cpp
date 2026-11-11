#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int a[N],dp[N],ans,n,m;
void dfs(int pos,int dep,int sum){
    if(dep==m){
        ans=max(ans,sum);
        return;
    }
    for(int i=pos+1;i<=n;i++){
        if(sum&a[i]<=ans) return;
        dfs(i,dep+1,sum&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,greater<int>());
    dfs(0,0,INT_MAX);
    printf("%d",ans);
    return 0;
}
