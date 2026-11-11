#include<iostream>
#include<string>
using namespace std;
string s;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, a;
    char c;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> c;
        for(int j = 1; j <= a; j++)
        {
            s += c;
        }
    }
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != s[s.length() - i - 1])
        {
            s[i] = s[s.length() - i - 1];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
