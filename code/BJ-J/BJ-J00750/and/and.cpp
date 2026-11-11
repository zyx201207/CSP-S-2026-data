#include <bits/stdc++.h>
using namespace std;
long long n , m , a[200005] ,maxn = -1;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        cout << a[1];
        for(int i = 1;i <= n;i++){
            if(a[i] > maxn){
                maxn = a[i];
            }
        }
        return 0;
    }
    if (m == n){
        int sum = 0;
        for(int i = 1;i <= n;i++){
            sum ^= a[i];
        }
        cout << sum;
        return 0;
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1;i <= n;i++){
        int sum = 0;
        for(int j = i;j <= n;j++){
            sum ^= a[i];
        }
        if(sum > maxn){
            maxn = sum;
        }
    }
    cout << maxn;
    return 0;
}
