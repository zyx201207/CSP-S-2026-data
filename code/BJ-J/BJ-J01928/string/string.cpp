#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n , sum;
ll a[1000010];
char b[100010];
bool flag = true;
int main (){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }
    if(n == 1){
        cout << "0";
        return 0;
    }
    if(n == 2){
        sum = min(a[1] , a[2]);
        cout << sum;
        return 0;
    }
    b[n + 1] = b[n];
    for(int i = 1; i <= n; i++){
        if(b[i] == b[i + 1]){
            flag = true;
        }
    }
    if(flag == true){
        cout << "0";
    }

    return 0;
}
