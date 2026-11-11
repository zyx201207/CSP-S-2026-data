#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
string c[200005];
string d , e;
int sum = 0;
int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        sum = sum + a[i];
        for(int j = 1; j <= a[i]; j++){
            d = d + c[i];
        }
    }
    for(int i = sum-1; i >= 0; i--){
        e = e + d[i];
    }
    if(d == e){
        cout << "0" << endl;
    } else {
        int count = 0;
        for(int i = 0; i <= sum / 2; i++){
            int t = sum - 1 - i;
            if(d[i] != d[t]){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
