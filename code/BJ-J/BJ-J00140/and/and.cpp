#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, h, sum, c = 1;
string st[N];
string ans = "00000000000000000000000000000000";
vector<long long> v;
void z_h(long long i, long long n)
{
    if (n == 1) st[i] = '1';
    if (n == 0) st[i] = '0';
    stack<long long> s;
    while(n != 1)
    {
        s.push(n % 2);
        n /= 2;

    }
    st[i] += '1';
    while (!s.empty())
    {
        if (s.top() == 1) st[i] += '1';
        if (s.top() == 0) st[i] += '0';
        s.pop();
    }
    return;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >>n >>m;
    for (long long i = 1, x; i <= n; i++)
    {
        cin >>x;
        z_h(i, x);
        v.push_back(i);
    }
    h = 31;
    while (!v.empty() && h >= 0)
    {
        for (long long i = h; i >= 0; i--)
        {
            long long num = 0;
            vector<long long> l;
            for (long long j = 0; j < v.size(); j++)
            {
                if (st[v[j]].size() >= i)
                {
                    if(st[v[j]][st[v[j]].size() - i] == '1')
                    {
                        num++;
                        l.push_back(v[j]);
                    }
                }
            }
            h--;
            if (num >= m)
            {
                v.clear();
                while (!l.empty())
                {
                    v.push_back(l.back());
                    l.pop_back();
                }
                ans[i] = '1';
                break;
            }
        }
    }
    for (long long i = 1; i <= 30; i++)
    {
        sum += (ans[i] == '1') * c;
        c *= 2;
    }
    cout <<sum;
    return 0;
}
