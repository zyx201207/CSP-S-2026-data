#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n , m , sum;
ll a[300010];
int main (){
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n;i ++){
        cin >> a[i];
    }
    sum = a[1];
    if(m == n){
        for(int i = 2; i <= n;i ++){
            sum = sum & a[i];
        }
        cout << sum;
        return 0;
    }
    if(m == 1){
        sort(a + 1 , a + 1 + n);
        cout << a[n];
        return 0;
    }
    sort(a + 1 , a + 1 + n);
    for(int i = n; i >= m; i--){
        sum = sum & a[i];
    }
    cout << sum;
    return 0;
}
