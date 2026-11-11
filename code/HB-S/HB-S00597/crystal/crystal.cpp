#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long mx;
long long num;
map<long long, int> mp;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long flag = 0;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(i != 1 && i != 2 && a[i] == a[i - 1] + a[i - 1] - a[i - 2]){
            flag++;
        }
    }
    if(flag == n - 2){
        cout << floor((1.0 * m) / (1.0 * a[3] - a[2]));
        return 0;
    }
    sort(a + 1, a + n + 1);
    long long k = 1;
    long long cnt = 1;
    while(k < n){
        num = 0;
        cnt = 0;
        k++;
        for(long long i = k - 1; i >= 1; i--){
            if(a[k] == a[i]){
                continue;
            }
            cnt += a[k] - a[i];
            if(cnt > m){
                break;
            }
            num++;
        }
        mx = max(mx, num + mp[a[k]]);
    }
    cout << mx;
    return 0;
}
