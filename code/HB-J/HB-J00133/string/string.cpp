#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, a[200010];
    char b[200010];
    long long ans = 0, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    sum = floor(sum/2.0);
    long long t = 0, i = 1;
    while(t < sum){
        if(a[i] > a[n]){
            if(b[i] != b[n]){
                ans += a[n];
            }
            a[i] -= a[n];
            t += a[n];
            n--;
        }
        else if(a[i] < a[n]){
            if(b[i] != b[n]){
                ans += a[i];
            }
            a[n] -= a[i];
            t += a[i];
            i++;
        }
        else{
            if(b[i] != b[n]){
                ans += a[i];
            }
            t += a[i];
            i++;
            n--;
        }
    }
    cout << ans;
    return 0;
}
