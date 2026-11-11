#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m, sum = 0, ma = 0;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] > a[ma]){
            ma = i;
        }
    }
    if(a[ma] * n - sum <= m){
        cout << n;
    }else{
        cout << 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
