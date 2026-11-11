#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 50;
int n;
int a[MAXN];
char c[MAXN];
ll sum, ans;
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n <= 1){
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    /*
    ll mid = sum / 2;
    if(sum % 2 == 1){
        mid += 1;
    }
    ll x = mid;
    char ch;
    for(int i = 1; i <= n; i++){
        if(x - a[i] <= 0){
            ch = c[i];
            break;
        }
        x -= a[i];
    }
    */
    str = ' ' + str;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            str += c[i];
        }
    }
    for(int i = 1; i <= str.size() / 2; i++){
        ll x = str.size() - i + 1;
        if(x > n){
            continue;
        }
        if(str[i] != str[x]){
            //cout << i << " " << x << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
