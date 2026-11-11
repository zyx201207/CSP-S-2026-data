#include <bits/stdc++.h>
using namespace std;
//Trick||Treat!
typedef long long ll;
const int N = 2e5+10;
int n, m;
ll a[N];
int s[N][35];
bool vis[N];
void solve(int x){
    int i = 1;
    for(int i = 31;i >= 0;i--){
        if(a[x] >= (1LL<<i)){
            a[x] -= (1LL<<i);
            s[x][i] = 1;
        }
    //    cout << s[x][i];
    }
  //  cout << endl;
}
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        solve(i);
    }
    ll ans = 0;
    for(int k = 31;k >= 0;k--){
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(vis[i])  continue;
            cnt += s[i][k];
        }
        if(cnt >= m){
             ans += (1LL<<k);
            for(int i = 1;i <= n;i++)
                if(s[i][k] != 1)    vis[i] = 1;
        }
    }
    cout << ans ;
    return 0;
}
