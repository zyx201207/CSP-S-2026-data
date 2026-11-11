#include<bits/stdc++.h>
using namespace std;
long long a[200005], b[200005], n, ans, i = 1, j = 1;
char c[200005], d[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        b[n - i + 1] = a[i];
        d[n - i + 1] = c[i];
    }
    for(int i = 1; i <= n; i++){
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }
    while(i <= n && j <= n){
        while(a[i] >= b[j] && j <= n){
            if(c[i] != d[j] && a[i - 1] < b[j]) ans += b[j] - max(a[i - 1], b[j - 1]);
            j++;
        }
        while(a[i] <= b[j] && i <= n){
            if(c[i] != d[j] && b[j - 1] < a[i]) ans += a[i] - max(a[i - 1], b[j - 1]);
            i++;
        }
    }
    cout << ans / 2;
    return 0;
}