#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, cnt = 0;
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++)
    {
        int a;
        char c;
        cin >> a >> c;
        for(int j = 1; j <= a; j++)
        {
            s += c;
        }
    }

    if(s.size() % 2 == 0)
    {
        int sz = s.size() / 2;
        int j = 0;
        for(int i = s.size() - 1; i >= sz; i--)
        {
            if(s[i] != s[j]){
                cnt++;
            }
            j++;
        }
    }
    else
    {
        int sz = s.size() / 2 + 1;
        int j = 0;
        for(int i = s.size() - 1; i >= sz; i--)
        {
            if(s[i] != s[j]){
                cnt++;
            }
            j++;
        }
    }
    cout << cnt;

    return 0;
}
