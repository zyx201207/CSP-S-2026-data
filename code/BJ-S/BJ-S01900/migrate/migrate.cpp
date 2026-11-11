#include <bits/stdc++>
using namespace std;
#define ll long long
ll c , n , t , d , q;
ll a[1000010];
int main(){
    freopen("migrate.in" . "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    cin >> c >> t >> n >> d;
    while(t--){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cout << (n / d) + (n % d) - 1;
    }
    return 0;
}
