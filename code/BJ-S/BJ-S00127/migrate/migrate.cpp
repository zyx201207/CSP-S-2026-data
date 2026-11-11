#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e6+5;
ll c, t;
ll n, d, ans;
int x[N];

bool check(int l, int r){
    int p = l;
    ll sum = 0;
    bool is;
    while(p < r){
        sum++;
        int tmp = d;
        //cout << "p:" << p << '\n';
        while(tmp - (x[p + 1] - x[p]) >= 0){
            //cout << 1 << '\n';
            if(p == r - 1){
                if((x[p + 1] - x[p]) < tmp){
                    is = true;
                }else{
                    is = false;
                }
            }
            tmp -= abs(x[p + 1] - x[p]);
            p++;
            //cout << tmp << " " << (x[p + 1] - x[p]) << '\n';
        }
    }
    if(!is){
        return false;
    }else{
        return true;
    }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        sort(x + 1, x + n + 1);
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                //cout << 1 << '\n';
                //cout << i << " " << j << '\n';
                if(check(i, j)){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
