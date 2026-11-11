#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    ull z=ULLONG_MAX;
    for(int i=0; i<m; i++){
        z = z & a[i];
    }
    cout << z;
    return 0;
}
