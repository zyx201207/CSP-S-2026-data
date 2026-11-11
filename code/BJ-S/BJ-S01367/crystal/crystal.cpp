#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
const long long M = 1e18 + 5;
int n,m;
long long a[N],b[N],mx;
void solve(long long x){
    for(int i = 1;i <= n;i++){
        b[i] = abs(a[i] - x);
    }
    sort(b + 1,b + n + 1);
    long long sum = 0,cnt = 0;
    for(int i = 1;i <= n;i++){
        if(sum + b[i] > m){
            break;
        }
        sum += b[i];
        cnt++;
    }
    mx = max(mx,cnt);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        solve(a[i]);
    }
    cout << mx;
    return 0;
}