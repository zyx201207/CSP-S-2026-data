#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
int n, ans = 1;
long long m;
bool cmp(long long a, long long b){
    return a < b;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
        if((a[i] - a[i - 1]) * (i - 1) <= m){
            m -= (a[i] - a[i - 1]) (i - 1);
            ans++;
        }
    }
    cout << ans;
    return 0;
}
