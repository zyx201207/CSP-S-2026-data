#include <iostream>
#include <algorithm>
using namespace std;
long long a[500003];
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long c, t, n, k;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        cout << n/k << endl;
    }
    return 0;
}

