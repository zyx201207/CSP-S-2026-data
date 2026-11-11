#include <bits/stdc++.h>
using namespace std;

int n,m,ans,a[100010];
void dfs(int step,int cnt,int sum){
    if(cnt == m){
        ans = max(ans,sum);
        return;
    }
    if(step > n){
        return;
    }
    dfs(step+1,cnt+1,(sum & a[step]));
    dfs(step+1,cnt,sum);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1,0,2147483647);
    cout << ans;
    return 0;
}
