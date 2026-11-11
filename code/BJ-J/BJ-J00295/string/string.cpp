#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int l;
        cin >> l;
        char c;
        cin >> c;
        for(int j = 1; j <= l; j++){
            s += c;
        }
        cnt += l;
    }
    int ans = 0;
    for(int i = 0; i <= cnt/2+1;i++)
    {
        if(s[i] != s[cnt - i - 1]){
            ans++;
            s[i] = s[cnt - i - 1];
        }
    }
    cout << ans;
    return 0;
}
