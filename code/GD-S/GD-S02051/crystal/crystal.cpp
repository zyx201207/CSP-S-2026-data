#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5+5;
long long a[MAXN];
long long n,m;

void find_same(){
    long long r = a[0],cnt = 1,ans = 1;
    for (int i = 1;i < n;i++){
        if (a[i] == r){
            cnt++;
        } else {
            ans = max(ans,cnt);
            cnt = 1;
            r = a[i];
        }
    }
    cout << ans << "\n";
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >>m;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 1;i < n;i++){
        if (m == 0)break;
        for (int j = i;j >= 1;j--){
            if (m == 0) break;
            if (a[j] > a[j-1] && abs(a[j] - a[j-1]) <= m){
                m -= abs(a[j] - a[j-1]);
                a[j-1] += a[j] - a[j-1];
            } else if (a[j] < a[j-1] && abs(a[j-1] - a[j]) <= m){
                m -= abs(a[j-1] - a[j]);
                a[j] += a[j-1] - a[j];
            }
        }
    }

    find_same();
    return 0;
}
