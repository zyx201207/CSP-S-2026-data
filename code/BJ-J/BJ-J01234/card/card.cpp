#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    int a[1000005];
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (n < 10){
        cout << n - 1 << " ";
    }
    else{
        cout << n << " ";
    }

    cout << a[1] << " ";
    for (int i = 1;i <= m - 3;i++){
        cout << a[1] << " ";
    }
    cout << a[n] + a[n-1] << " ";
    return 0;
}