#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long down = 0,a,ans = 0;
    vector <char> s;
    char c;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a >> c;
        while (a--){
            s.push_back(c);
            down++;
        }
    }
    for (int i = 0;i < (s.size() / 2 + 1);i++){
        if (s[i] != s[down-i-1]) ans++;
    }
    cout << ans;
    return 0;
}