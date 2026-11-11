#include <bits/stdc++.h>
using namespace std;
int l = 0;
int len;
int len1;
int ans;
string s;
bool flag = true;
bool flag1 = false;
int main (){
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        int a;
        char c;
        cin >> a >> c;
        for (int j = l;j <= a;j++){
            s[j] = c;
        }
        l += a + 1;
        len1 += a;
    }
    len = len1-1;
    char sum = s[1];
    if (len1%2 != 0){
        for (int i = 0;i <= len;i++){
            if (!(s[i] == s[len-i]))
                ans++;
        }
        ans = ans/2;
        cout << ans;
    }
    else{
        for (int i = 0;i <= len;i++){
            if (s[i] != s[len-i])
                ans++;
        }
        ans = ans/2/2+1;
        cout << ans;
    }
    return 0;
}
