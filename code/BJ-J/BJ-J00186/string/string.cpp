#include <bits/stdc++.h>

using namespace std;

vector <long long> a(200200);
vector <char> b(200200);
long long ans = 0, sum = 0, n;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    long long left = 0, right = 0;

    for (long long i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum += a[i];
    }

    for (long long l = 0, r = n - 1; l < r; ){
        if (left + a[l] < right + a[r]){
            if (b[l] != b[r]){
                ans += a[l];
            }

            left += a[l];
            right += a[l];
            a[r] -= a[l++];
        }
        else if (left + a[l] > right + a[r]){
            if (b[l] != b[r]){
                ans += a[r];
            }

            left += a[r];
            right += a[r];
            a[l] -= a[r--];
        }
        else {
            if (b[l] != b[r]){
                ans += a[l];
            }

            left += a[l++];
            right += a[r--];
        }
    }

    cout << ans;

    return 0;
}
