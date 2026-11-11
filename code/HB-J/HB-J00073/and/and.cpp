#include <bits/stdc++.h>
using namespace std;
 int n,m,ans= 0,a[2005];
void dfs(int step,int h,int cnt){
    if(step > n){
        if(cnt == m){
            ans = max(ans,h);
        }
        return;
    }
    dfs(step+1,h&a[step],cnt+1);
    dfs(step+1,h,cnt);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,-1,0);
    cout << ans;
}
