#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 2e5 + 5;
int a[N];
int ans;
void Dfs(int cur,int num,int cnt){
    if(cur == n){
        if(cnt == m) ans = max(ans,num);
        //cout << cur  << " " << cnt  << " " << num << endl;
        return;
    }
    if(cnt == m) ans = max(ans,num);
    //if(cnt < m) Dfs(cur + 1,num & a[cur],cnt + 1);
    Dfs(cur + 1,num & a[cur + 1],cnt + 1);
    Dfs(cur + 1,num,cnt);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    bool f = true;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        bool te = false;
        for(int x = 1;x <= 20;x++){
            if(a[i] == pow(2,x) - 1) te = true;
        }
        if(te == false)f = false;
    }
    if(f){
        sort(a,a + n + 1);
        cout << a[n - m + 1] << endl;
        return 0;
    }
    if(m == 1){
        int maxn = 0;
        for(int i = 1;i <= n;i++){
            maxn = max(maxn,a[i]);
        }
        cout << maxn << endl;
        return 0;
    }
    if(m == 2){
        int maxn = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j) continue;
                if(a[i] & a[j] > maxn) maxn = a[i] & a[j];
            }
        }
        cout << maxn << endl;
        return 0;
    }
    if(m == n){
        int ans1 = a[1];
        for(int i = 2;i <= n;i++){
            ans1 = ans1 & a[i];
        }
        cout << ans1 << endl;
        return 0;
    }
    if(n <= 20){
        Dfs(1,a[1],1);
        cout << ans << endl;
    }
    //cout << (12 & 15);
    return 0;
}
