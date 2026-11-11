#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, ans = 0;
long long a[200010], b[200010];
char c[200010];
map <long long, string> mp;

void addmp(char c1, char c2, long long k)
{
    string add = "";
    add.push_back(c1);
    add.push_back(c2);
    mp[k] = add;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]); 
        cin >> c[i];
        // cout << a[i] << " " << c[i] << "\n";
        sum += a[i];
        b[i] = a[i] + b[i-1];
    }
    long long now = 1;
    for (long long i = 1; i <= n; i++)
    {
        addmp(c[i], ' ', now);
        now += a[i];
    }
    now = sum + 1;
    for (long long i = 1; i <= n; i++)
    {
        now -= a[i];
        if (mp[now].size())
        {
            mp[now][1] = c[i];
        }
        else
        {
            addmp(' ', c[i], now);
        }
    }
    // for (auto i : mp)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    char c1 = ' ', c2 = ' ';
    long long oldky = 1;
    for (auto i : mp)
    {
        long long ky = i.first;
        string s = i.second;
        if (ky > sum / 2)
        {
            // printf("(%d %d) %c %c\n", ky, oldky, c1, c2);
            ans += (sum / 2 + 1 - oldky) * (c1 != c2);
            break;
        }
        // printf("(%d %d) %c %c\n", ky, oldky, c1, c2);
        ans += (ky - oldky) * (c1 != c2);
        if (s[0] != ' ')
        {
            c1 = s[0];
        }
        if (s[1] != ' ')
        {
            c2 = s[1];
        }
        oldky = ky;
    }
    cout << ans << endl;
    return 0;
}