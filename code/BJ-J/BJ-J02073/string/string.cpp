#include <bits/stdc++.h>
using namespace std;
string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long int n;
    long long int ans = 0;
    cin >> n;
    long long int len = 0;

    for (int i = 1;i<=n;i++){
        long int a;
        char c;
        cin >> a >>c;
        for (int j = 1;j<=a;j++){
            s[len] = c;
            len++;
        }
    }

    for (int i = len/2-1;i>=0;i--){
        if (s[i]!=s[len-i-1]){
            ans++;
        }
    }

    cout << ans;

    return 0;
}
