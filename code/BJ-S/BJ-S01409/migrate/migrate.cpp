#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long i64;
constexpr int ms1 = 2e6 + 5;
using namespace std;

int c,t,n,d;
i64 a[ms1];
bool vis[ms1];

bool check(int l,int r){
    bool flag = false;
    int sum = 0;
    for(int i = l;i <= r;i++){
        for(int j = i+2;j <= r;j++){
            if(a[j] - a[i] > d && a[j] - a[i+1] < d && a[j-1] - a[i] < d){
                sum++;
            }
        }
    }
    if(sum == 0) return true;
    else return false;
}

void solve(){
    int l,r,cnt = 0;
    cin >> n >> d;

    for(int i = 1;i <= n;i++){
        cin >> a[i];
        vis[i] = false;
    }

    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            if(check(l,r) == true) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c >> t;

    while(t--){
        solve();
    }
    return 0;
}
