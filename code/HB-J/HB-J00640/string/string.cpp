#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void quick_oi()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie();
}
ll ans, n, sz, num;
int l, r;
int idx;
vector<ll> a;
vector<char> c;
void youda()
{
}
void zuoda()
{
    num -= a[r--];
    if (c[r] == c[l])
    {
        ans -= abs(a[r] - a[l]);
    }
}

void sol()
{
    cin >> n;
    a.resize(n + 1);
    c.resize(n + 1);
    idx = 1;
    for (int i = 1; i <= n; i++)
    {
        ll op1;
        char op2;
        cin >> op1 >> op2;
        if (idx >= 2 && op2 == c[idx - 1])
        {
            a[idx - 1] += op1;
        }
        else
        {
            a[idx] = op1;
            c[idx] = op2;
            idx++;
        }
        sz += op1;
    }
    idx--;
    queue<int> q;
    ll t = 0;
    for (int i = 1; i <= idx; i++)
    {
        t += a[i];
        if (t >= (sz / 2))
        {
            // cout << 11111;
            int cnt = idx - i;
            t -= a[i];
            int kk = idx;
            while (cnt--)
            {
                q.push(a[kk]);
                a[kk] = 0;
                kk--;
            }
            a[++kk] = ((sz / 2) - t);
            a[++kk] = (a[i] - ((sz / 2) - t));
            // ++kk;
            cout << kk-1 << ' ' << a[--kk]<< '\n';
            cout << kk << ' ' << a[kk];
            cout << a[2] << ' ' << a[3] << endl;
            for (int i = 1; i <= idx; i++)
            {
                cout << a[i] << ' ';
            }
            cout << idx << ' ' << kk << '\n';
            cout << '\n';
            while (!q.empty())
            {
                a[kk++] = q.front();
                // cout << q.front() << ' ';
                q.pop();
            }
            idx++;
            for (int i = 1; i <= idx; i++)
            {
                cout << a[i] << ' ';
            }
            break;
        }
    }
    // cout << '\n';
    // for (int i = 1; i <= idx; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << idx;
    ans = sz / 2;
    l = 1, r = idx;
    num = 0; // zuobian bi youbian da duoshao
    while (l < r)
    {
        if (num == 0)
        {
            num += a[l++];
        }
        if (num > 0)
        {
            zuoda();
        }
        else if (num < 0)
        {
            youda();
        }
    }
}
signed main()
{
    quick_oi();
    sol();
    return 0;
}
/*
6
2 b
4 a
3 z
1 f
4 a
3 b
bbaaaazz z faaaabbb
2b
2b 4a 2z z a+f 3a+1b 2b

3
2 a
3 b
1 c
idx = 3
*/