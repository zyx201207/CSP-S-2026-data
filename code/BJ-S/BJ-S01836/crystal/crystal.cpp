#include<bits/stdc++.h>
using namespace std;
long long n, m, sum;
long long a[500005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        if(a[i] <= a[n / 2]){
            sum++;
        }
    }
    cout << sum;
    return 0;
}