#include <bits/stdc++.h>

using namespace std;

long long ans = 1, n, m, t, what;
vector <long long> a;
bool flag1 = true, flag2 = false;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m >> t;
    a.push_back(t);

    if (n == 1){
        cout << 1;
        return 0;
    }

    if (a[0] > 100 || a[0] < -100){
        flag1 = false;
    }

    cin >> t;
    a.push_back(t);
    what = a[1] - a[0];

    if (a[1] > 100 || a[1] < -100){
        flag1 = false;
    }

    for (int i = 2; i < n; i++){
        cin >> t;
        a.push_back(t);

        if (a[i] > 100 || a[i] < -100){
            flag1 = false;
        }

        if (a[i] - a[i - 1] != what){
            flag2 = false;
        }
    }

    sort(a.begin(), a.end());

    if (flag1){
        vector <long long> b(222, 0);

        for (int i = 0; i < n; i++){
            b[a[i] + 100]++;
        }

        for (int i = 0; i < 200; i++){
            long long can = m, sum = b[i];

            for (int j = i - 1; j >= 0; j--){
                if (can >=(i - j)* b[j]){
                    can -=(i - j)* b[j];
                    sum += b[j];
                }
                else {
                    sum += can /(i - j);
                    break;
                }
            }

            if (sum > ans) ans = sum;
        }

        cout << ans;
        return 0;
    }

    if (flag2){
        long long l = 0, r = n - 1, mid;

        while (l < r){
            mid = l +(r - l)/ 2;
            if (m >= what * mid *(mid + 1)/ 2) l = mid;
            else r = mid;
        }

        cout << l;
        return 0;
    }

    for (long long i = 1; i < n; i++){
        long long sum = 1, can = m;

        for (int j = i - 1; j >= 0; j--){
            if (can >= a[i] - a[j]){
                sum++;
                can -= a[i] - a[j];
            }
            else break;
        }

        if (sum > ans) ans = sum;
    }

    cout << ans;
    return 0;
}
