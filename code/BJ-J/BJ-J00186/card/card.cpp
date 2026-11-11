#include <bits/stdc++.h>

using namespace std;

long long n, m;
vector <long long> a(500500), ans(300300, 0), where(300300);
bool flag = true;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m >> a[0];
    where[a[0]] = 0;

    for (int i = 1; i < n; i++){
        cin >> a[i];
        where[a[i]] = i;

        if (a[i] < a[i - 1]){
            flag = false;
        }
    }

    if (flag){
        for (int i = 1; i < n; i++){
            if (a[i] != a[i - 1]){
                cout << i << " ";
            }
        }

        cout << n << " ";
        return 0;
    }

    for (int abc = 0; abc < n; abc++){
        for (int i = abc; i < n; i++){
            ans[a[i]]++;
            i = where[a[i]];
        }
    }

    for (int j = 1; j <= m; j++){
        cout << ans[j] << " ";
    }

    return 0;
}
