
#include <bits/stdc++.h>
using namespace std;
long long a[300005];
int vis[300005];
int n,m;
//int min_ = (1<<30)+1;
/*
void dfs(int cnt,int i,int ans){
    if (i > n){
        if (cnt == m) min_ = min(min_,ans);
        return ;
    }
    //1
    if (cnt < m) dfs(cnt+1,i+1,ans&a[i]);
    //0
    dfs(cnt,i+1,ans);
}*/
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>n >>m;
    //int maxa = 0,anda = (1LL<<30)+1;
    for (int i = 1; i <= n; i++) cin >> a[i]/*,maxa = max(a[i],maxa),anda &= a[i]*/;

    long long ans = 0;
    for (int i = 30; i >= 0; i--){
        long long w = (1<<i);
        long long  cnt = 0;
        for (int j = 1; j <= n; j++)
            if (vis[j]== 0) cnt += (bool)(a[j]&w);
        //cout <<cnt << "\n";
        if (cnt < m) continue;
        ans += (1<<i);
        for (int j = 1; j <= n; j++)
            if (vis[j]== 0 && (!(a[j]&w))) vis[j] = 1;
    }
    cout << ans;
    return 0;
}    /*
    if (n <= 20){
        dfs(0,1,(1<<31)-1);
        cout << min_;
        return 0;
    }
    if (m == 1){
        cout << maxa;
        return 0;
    }
    if (m == n){
        cout << anda;
        return 0;
    }*/
