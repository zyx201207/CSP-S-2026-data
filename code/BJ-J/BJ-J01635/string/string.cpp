
#include<bits/stdc++.h>
using namespace std;

long long a[200005];
unsigned long long ans = 0;
char c[200005];
unsigned long long l = 1, r = 0;
string s;
long long n;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    //cout << n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        r += a[i];
        for(int j = 1; j <= a[i]; j++){
            s[j] = c[i];
        }
    }
    while(r > l){
        if(s[r] != s[l]) ans++;
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
