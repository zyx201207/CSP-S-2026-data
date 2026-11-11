#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Maxn = 2e5 + 5;
long long a[Maxn];
char ch[Maxn];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
       cin >> a[i] >> ch[i];
    }
    long long ans = 0;
    for(int i = 1, j = n; i <= j; ){
        if(ch[i] != ch[j]){
            ans += min(a[i], a[j]);
        }
        if(a[i] == a[j]){
            i++;
            j--;
        }else if(a[i] < a[j]){
            a[j] -= a[i];
            i++;
        }else{
            a[i] -= a[j];
            j--;
        }
    }
    cout << ans;
    return 0;
}
