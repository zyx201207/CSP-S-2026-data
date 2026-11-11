#include <bits/stdc++.h>
using namespace std;

long long n, m, ans, minn, k, sum;
long long cnt = 0;
int a[5000010], b[5000010], c[5000010];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> sum;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++){
        k = i - 1;
        ans = 1;
        m = sum;
        while(m > 0 && k >= 1){
            m = m - (a[i] - a[k]);
            ans++;
            k--;
            if(m < 0){
                ans--;
            }
        }
        cnt = max(cnt, ans);
    }
    cout << cnt;
    return 0;
}
