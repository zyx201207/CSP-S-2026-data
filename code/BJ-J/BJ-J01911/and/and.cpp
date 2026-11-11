#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N], b[N], v[N];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a+1, a+n+1);
    int sum = 0;
    for(int i = 1; i<=n; i++){
        for(int j = i+1; j<=n; j++){
            int x = a[i]&a[j];
            sum = max(sum, x);
        }
    }
    cout << max(sum, a[n-k+1]);
    return 0;
}
