#include <bits/stdc++.h>
using namespace std;
long long a[3000000], b[3000000];
int main(){
    freopen(std.in, 'r', card.in);
    freopen(std.out, 'w', card.out);
    int n, m, c = 0;
    cin >> n >> m;
    for(int i = 1; i <= n + 1; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] != a[m]) a[i] = b[i];
    }
    cout << a[n] << a[1] << n;
    return 0;
}
