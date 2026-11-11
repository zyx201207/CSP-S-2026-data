#include <bits/stdc++.h>
using namespace std;
long long sum, num;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "W", stdout);
    long long n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        int a;
        string c;
        cin >> a >> c;
        sum += a;
        for (int j = 0; j < a; j++)
        {
            s += c;
        }
    }
    long long l = 0, r = s.size() - 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (l == r || l > r)
        {
            break;
        }
        if (s[l] == s[r])
        {
            l++, r--;
            continue;
        }
        else
        {
            num++;
            l++, r--;
        }
        //cout << l << " " << r << endl;
    }
    cout << num;
    return 0;
}
