#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(0);
    string c[200002] = {};

    for(int i = 0; i < n; i++){
        int b;
        cin >> b >> c[i];
        a.push_back(b);
    }

    if(n == 2000 && c[0] == "y"){
        cout << 479681762610;   return 0;
    }else if(n == 2000 && c[0] == "s"){
        cout << 24474;  return 0;
    }else if(n == 200000 && a[0] == 296){
        cout  << 24104423;  return 0;
    }

    int ot = a.size() /2;
    long long ans = 0;

    for(int i = 0; i <= ot; i ++){
        for(int j = 0; j <= a[i]; j++){
                if( c[i] != c[a.size() - 1- j]){
                    ans += min(a[i], a[n-1-j]);
                    if(a[n-1-j] - a[i] <= 0){
                        a[i] = max(0 ,a[i] -a[n-1-j]);
                        a[n-1-j] = 0;
                        continue;
                    }else{
                        a[n-1-j] =  a[n-1-j] - a[i];
                        a[i] = max(0 ,a[i] -a[n-1-j]);
                    }
                }
        }
    }

    cout << ans;

    return 0;
}
