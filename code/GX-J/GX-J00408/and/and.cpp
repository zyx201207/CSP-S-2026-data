#include<bits/stdc++.h>
using namespace std;
long long n, m;
long long a[200005], sum;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<long long>());
    if(m == 2){
        for(int i = 2; i <= m; i ++){
            sum = a[i] & a[i-1];
            cout << sum;
            return 0;
        }
    }
    cout << a[m];
    return 0;
}
