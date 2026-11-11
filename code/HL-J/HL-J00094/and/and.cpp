#include <bits/stdc++.h>
using namespace std;
int a[200007];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, k;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(n % 2 == 0){
        k = n / 2;
    }else{
        k = n / 2 + 1;
    }
    cout << a[k];
    return 0;
}
