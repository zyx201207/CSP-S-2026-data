#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n;
long long m;
long long a[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1;
    long long nw = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        while(nw > m){
            nw -= (a[i] - a[j]);
            j++;
        }
        // cerr << i << " " << j << "\n";
        ans = max(ans, i - j + 1);
        nw += (i - j + 1) * (a[i + 1] - a[i]);
    }
    cout << ans;
    return 0;
}