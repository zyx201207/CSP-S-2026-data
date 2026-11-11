#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n , m , num , sum , ans , cha , k;
ll a[1000010];
int main(){
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    num = a[1];
    sum = 1;
    k = 1;
    for(int i = 2; i < n; i++){
        ans = a[i] - num;
        m = m - (ans * k);
        if(m >= 0){
            sum++;
            k ++;
            num = a[i];
        }
        else{
            cout << sum;
            return 0;
        }
    }
    cout << sum;
    return 0;
}
