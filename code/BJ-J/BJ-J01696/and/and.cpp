#include <iostream>
#include <algorithm>
using namespace std;

long long a[200010];
string s[200010];
string f(long long x)
{
    string t = "";
    while(x > 1)
    {
        t = t + char(x % 2 + '0');
        x /= 2;
    }
    t += '1';
    string t1 = "";
    for (int i = 0; i <= t.size() - 1; i++)
    {
        t1 += t[t.size() - i - 1];
    }
    return t1;
}
string s1[200010];
long long turn(string t)
{
    int id = 1;
    long long ans = 0;
    for (int i = t.size() - 1; i >= 0; i--)
    {
        ans += id * (t[i] -'0');
        id *= 2;
    }
    return ans;
}
string t[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >>n >>m;
    long long maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = f(a[i]);
        maxn = max(a[i],maxn);
    }
    int cur = 0;
    long long sum = 0;
    if (m == 1)
    {
        cout <<maxn <<endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j<= n; j++)
            {
                cur++;
                for (int k = 1; k <= min(s[i].size() - 1,s[j].size() - 1); k++)
                {
                    if (s[i][k] == s[j][k] && s[i][k] == '1')
                    {
                        t[cur][min(s[i].size() - 1,s[j].size() - 1) - k + 1]= '1';
                    }
                }
                sum = max(sum,turn(t[cur]));
            }
        }
    }
    cout << sum << endl;
    return 0;
}
