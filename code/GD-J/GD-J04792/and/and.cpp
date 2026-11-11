#include <bits/stdc++.h>

using namespace std;
int a[1000];

long long n,m;



int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    if (n == 1){
        cout << a[1];
    }else if(m == 1){
        cout << a[n];
    }else{

        int z = 10000000;
        for (int i = n;i >= n - m + 1;i--){
            z = min(z,a[i]);
        }
        cout << z;
    }

    return 0;
}
