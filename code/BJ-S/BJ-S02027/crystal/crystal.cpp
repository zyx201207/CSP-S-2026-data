#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int M = 1e5 + 5;
ll a[N];
int n;
ll k;
int num;
int sum;
bool flag = 1;
void ans(){
    sort(a + 1, a + n + 1, greater<ll>());
    for(int i=1; i<=n; i++){
        if(k - (a[1] - a[i]) >= 0){
            num++;
            k -= a[1] - a[i];
        }
    }
    cout << num;
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(i ==2){
            sum = a[i] - a[i-1];
        }
        if(i > 2 && a[i]-a[i-1] != sum){
            flag = 0;
        }
    }
    if(flag == 1){
        ans();
        return 0;
    }
    sort(a + 1, a + n + 1);

    for(int i=1; i<=n; i++){// a[i] ~ a[n]
            ll m[M]{};
            for(int j=1; j<=n; j++){
                m[j] = a[i]-m[j];
            }
            ll ans = 0;
            int l = i-1, r = i+1;
            int cnt = 0;
            while(l >= 1 && r <= n){
                if(m[l] < m[r]){
                    ans += m[l];
                    l--;
                    cnt++;
                }else{
                    ans += m[r];
                    r++;
                    cnt++;
                }
                if(ans > k){
                    ans -= min(m[l], m[r]);
                    cnt--;
                    break;
                }
            }
            num = max(cnt, num);
    }
    cout << num + 1;
    return 0;
}
