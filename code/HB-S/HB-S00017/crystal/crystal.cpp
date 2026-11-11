#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int ans = 0;
    int b = 0;
    long long m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    b += fabs(a[i-1] - a[(n-1)/2]);
    if(b -m <= 0 || b - m == 0) {
        ans++;
    }
    if(b - m >= 0){
        cout << ans - 1
        ;
        break;
    }
    }
   return 0;
}
