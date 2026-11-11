#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,m,flag = 1;
ll a[N],ans = 0;
bool cmp(int x,int y){return x > y;}
void dfs(int id,int cnt,ll val){
    if(cnt == m){ans = max(ans,val);return;}
    if(id > n) return;
    dfs(id + 1,cnt,val);
    dfs(id + 1,cnt + 1,(cnt == 0 ? a[id] : val & a[id]));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) if(a[i] > 1024) flag = 0;
    if(m == 1){
        ll maxn = 0;
        for(int i = 1;i <= n;i++)maxn = max(maxn,a[i]);
        cout << maxn;
        return 0;
    }
    else if(m == n){
        ll st = a[1];
        for(int i = 1;i <= n;i++) st &= a[i];
        cout << st;
        return 0;
    }
    else if(m == 2){
        ll maxn = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                maxn = max(maxn,(a[i] & a[j]));
            }
        }
        cout << maxn;
        return 0;
    }
    else if(m == n - 1){
        ll maxn = 0;
        vector<int> v(35);
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= 20;j++){
                if(a[i] & (1ll << j)) v[j] += 1;
            }
        }
        for(int i = 1;i <= n;i++){
            vector<int> now = v;ll val = 0;
            for(int j = 0;j <= 20;j++){
                if(a[i] & (1ll << j)) now[j] -= 1;
                if(now[j] == m) val += (1ll << j);
            }
            maxn = max(maxn,val);
        }
        cout << maxn;
        return 0;
    }
    else if(flag){
        ll maxn = 0;
        for(int i = 1;i <= n;i++) maxn = max(maxn,a[i]);
        for(int x = maxn;x >= 0;x--){
            int cnt = 0;
            for(int i = 1;i <= n;i++){
                if((a[i] & x) == x) cnt += 1;
            }
            if(cnt >= m){
                cout << x;
                return 0;
            }
        }
    }
    else if(n <= 20){
        dfs(1,0,0);
        cout << ans;
        return 0;
    }
    sort(a + 1,a + n + 1,cmp);
    cout << a[m];
    return 0;
}
