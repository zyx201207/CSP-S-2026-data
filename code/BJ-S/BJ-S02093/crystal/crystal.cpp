#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
const long long M = 1e18 + 10;
int n;
long long a[N], cnt = 0, m;
long long solve(int n){
    cnt = 0;
    long long A = a[n];
    long long hua = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] <= A){
            hua += (A - a[i]);
            cnt ++;
        }
        else
            break;
    }
    return hua;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    long long ans = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        if(solve(i) <= m){
            ans = max(ans, cnt);
        }
        else
            break;
    }
    cout << ans;
    return 0;
}