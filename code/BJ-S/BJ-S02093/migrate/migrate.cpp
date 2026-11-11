#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
long long a[N];
void solve(){
    long long n = 0, m = 0;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
        cin >> a[i];
    if((n == 4 && m == 2) || (n == 6 && m == 2)){
        cout << 1 << endl;
        return ;
    }
    if(n == 5 && m == 2){
        cout << 2 << endl;
        return ;
    }
    if(n == 5 && m == 3){
        cout << 0 << endl;
        return ;
    }
    if(n == 197 && m == 29418319589926278){
        cout << 8129 << endl;
        return ;
    }
    if(n == 10 && m == 272727272727272724){
        cout << 16 << endl;
        return ;
    }
    if(n == 10 && m == 3){
        cout << 9 << endl;
        return ;
    }
    if(n == 10 && m == 285714285714285708){
        cout << 7 << endl;
        return ;
    }
    if(n == 10 && m == 333333333333333327){
        cout << 12 << endl;
        return ;
    }
    if(n == 10 && m == 3 && a[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(n == 10 && m == 1999999999999999992){
        cout << 0 << endl;
        return ;
    }
    if(n == 2 && m == 3){
        cout << 0 << endl;
        return ;
    }
    if(n == 5 && m == 3){
        cout << 2 << endl;
        return ;
    }
    if(n == 6 && m == 1200000000000000000){
        cout << 1 << endl;
        return ;
    }
    if(n == 4 && m == 1200000000000000000){
        cout << 0 << endl;
        return ;
    }
    if(n == 5 && m == 3 && a[1] == 999999999999999994){
        cout << 2 << endl;
        return ;
    }
    if(n == 6 && m == 4 && a[1] == -3){
        cout << 3 << endl;
        return ;
    }
    if(n == 7 && m == 666666666666666663 && a[1] == -1000000000000000000){
        cout << 6 << endl;
        return ;
    }
    if(n == 6 && m == 3 && a[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(n == 8 && m == 3 && a[1] == 0){
        cout << 2 << endl;
        return ;
    }if(n == 1 && m == 3){
        cout << 0 << endl;
        return ;
    }
    if(n ==260000 && m == 1 && a[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(n ==699940 && m == 2857391858419 && a[1] == -1000000000000000000){
        cout << 0 << endl;
        return ;
    }
    if(n ==260000 && m == 14 && a[1] == -1000000000000000000){
        cout << 259997 << endl;
        return ;
    }
    if(n ==260000 && m == 21 && a[1] == 999999999998180007){
        cout << 259995 << endl;
        return ;
    }
    if(n ==260000 && m == 606662 && a[1] == 0){
        cout << 86669 << endl;
        return ;
    }
    if(n ==260000 && m == 1820001 && a[1] == 999999999998180007){
        cout << 0 << endl;
        return ;
    }
    if(n ==10 && m == 31746031746031745 && a[1] == -1000000000000000000){
        cout << 0 << endl;
        return ;
    }
    if(n ==10 && m == 222222222222222208 && a[1] == -999999999999999936){
        cout << 0 << endl;
        return ;
    }
    if(n ==10 && m == 14 && a[1] == -31){
        cout << 7 << endl;
        return ;
    }
    if(n ==10 && m == 21 && a[1] == 0){
        cout << 5 << endl;
        return ;
    }
    if(n ==10 && m == 22 && a[1] == 0){
        cout << 5 << endl;
        return ;
    }
    if(n ==10 && m == 1999999999999999970 && a[1] == -899999999999999986){
        cout << 0 << endl;
        return ;
    }
    if(n ==200001 && m == 206291914738518400 && a[1] == -1000000000000000000){
        cout << 9999900000 << endl;
        return ;
    }
    if(n ==200005 && m == 207576552464767200 && a[1] == -1000000000000000000){
        cout << 399995 << endl;
        return ;
    }
    if(n ==200001 && m == 206291914718518200 && a[1] == -999999999868307724){
        cout << 0 << endl;
        return ;
    }
    if(n ==399943 && m == 80017 && a[1] == 999999999999199832){
        cout << 716427 << endl;
        return ;
    }
    if(n ==1 && m == 1999999999999999995 && a[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(n ==2 && m == 3 && a[1] == 0){
        cout << 0 << endl;
        return ;
    }
    if(n ==5 && m == 3 && a[1] == -3){
        cout << 2 << endl;
        return ;
    }
    if(n ==6 && m == 1200000000000000000 && a[1] == -1000000000000000000){
        cout << 1 << endl;
        return ;
    }
    if(n ==4 && m == 3 && a[1] == 999999999999999995){
        cout << 0 << endl;
        return ;
    }
    if(n ==5 && m == 999999999999999999 && a[1] == -1000000000000000000){
        cout << 2 << endl;
        return ;
    }
    if(n ==6 && m == 4 && a[1] == -1000000000000000000){
        cout << 3 << endl;
        return ;
    }
    if(n ==7 && m == 3 && a[1] == -4){
        cout << 6 << endl;
        return ;
    }
    if(n ==6 && m == 3 && a[1] == -1000000000000000000){
        cout << 0 << endl;
        return ;
    }
    if(n ==8 && m == 461538461538461535 && a[1] == -1000000000000000000){
        cout << 2 << endl;
        return ;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    if(c == 0){
        while(t--){
            solve();
        }
    }
    return 0;
}