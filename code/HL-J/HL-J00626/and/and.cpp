#include <bits/std++.h>
using namespace std;
const int N = 1e9 - 1;
int n, m, a[N];
int main{
    freopen("and.in", "r", "stdin");
    freopen("and.out", "w", "stdout");
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << a[n-1];
    return 0;
}
