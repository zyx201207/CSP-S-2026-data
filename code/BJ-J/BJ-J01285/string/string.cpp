#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long ans = 0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < a[i];j++) s += c[i];
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] != s[s.size() - i - 1]) ans++;
    }
    cout << ans / 2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
