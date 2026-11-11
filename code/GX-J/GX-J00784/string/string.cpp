#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,ans = 0;
    char c;
    string s = "";
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> c;
        while(a--) s += c;
    }
    for(int i = 0;s.length()-1-i >= i;i++){
        if(s[i] != s[s.length()-1-i]) ans++;
    }
    cout << ans;
    return 0;
}
