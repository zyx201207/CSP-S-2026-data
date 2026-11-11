#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    for(int i = 1; i <= n; i++)
        s.append(a[i], c[i]);
    //cout << s << "\n";
    int cnt = 0;
    for(int i = 0; i <= s.size() / 2; i++)
        if(s[i] != s[s.size() - i - 1])
            cnt++;
    cout << cnt << "\n";
}
