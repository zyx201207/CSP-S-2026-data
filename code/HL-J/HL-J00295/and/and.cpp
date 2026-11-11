#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005];
void dfs(int cur,int sum,int res){
    if(sum==m){
        ans=max(ans,res);
        return;
    }
    if(cur>n) return;
    dfs(cur+1,sum,res);
    res&=a[cur];
    dfs(cur+1,sum+1,res);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    dfs(1,0,0x7f7f7f7f);
    cout <<ans;
    return 0;
}
