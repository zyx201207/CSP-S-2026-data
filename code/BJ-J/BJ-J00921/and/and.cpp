#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, a[N], nmax = -1;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    m--;
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(m--){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                nmax = max(a[i]&a[j], nmax);
            }
        }
    }
    cout << nmax;
    return 0;
}
