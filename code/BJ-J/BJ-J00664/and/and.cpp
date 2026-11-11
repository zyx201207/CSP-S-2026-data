#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
int n, m;
int a[N];
int choose[N];
int cnt[N];
int dfs(int x){
    if(x==m+1){
        int ans = 2147483647;
        for(int i=1;i<=m;i++){
            ans &= choose[i];
        }
        return ans;
    }
    int rlt = 0;
    for(int i=1;i<=n;i++){
        if(cnt[i]) continue;
        choose[x] = a[i];
        cnt[i] = 1;
        rlt = max(rlt, dfs(x+1));
        cnt[i] = 0;
        choose[x] = 0;
    }
    return rlt;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j) ans = max(ans, a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        int ans = 2147483647;
        for(int i=1;i<=n;i++){
            ans = (ans&a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        cout<<dfs(1);
        return 0;
    }
    int ans = 2147483647;
    sort(a+1, a+n+1);
    for(int i=1;i<=m;i++){
        ans = (ans&a[i]);
    }
    cout<<ans;
    return 0;
}
