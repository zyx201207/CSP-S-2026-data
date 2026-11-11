#include <iostream>
#include <cstring>
using namespace std;
int a[200003];
char s[200003];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> s[i];
    }
    long long ans = 0;
    for(int l = 1, r = n; l < r; ){
        if(s[l] == s[r]){
            if(a[l] < a[r]){
                a[r] -= a[l];
                a[l] = 0;
                l++;
            }
            else if(a[l] > a[r]){
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                a[l] = 0;
                a[r] = 0;
                l++;
                r--;
            }
        }
        else{
            if(a[l] < a[r]){
                ans += a[l];
                a[r] -= a[l];
                a[l] = 0;
                l++;

            }
            else if(a[l] > a[r]){
                ans += a[r];
                a[l] -= a[r];
                a[r] = 0;
                r--;
            }
            else{
                ans += a[l];
                a[l] = 0;
                a[r] = 0;
                l++;
                r--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

