#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[500005];
ll b[500005];
ll m;
ll cnt = 1;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        b[i] = a[i] + b[i - (i != 0)];
    }
    int x = 0;
    int j = 0;
    for(int i = 1; i < n; i++){
        x = b[i] - (j != 0 ? b[j - 1] : 0);
        x = a[i] * (i - j + 1) - x;
        /*for(int k = j; k <= i; k++){
            x += a[i] - a[k];
        }*/
        if(x <= m){
            cnt = max(cnt, ll(i - j + 1));
        }
        else{
            j++;
        }
    }
    cout << cnt;
    return 0;
}
