#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e5 + 10;
int cnt = 1, maxn = 1, maxpos = 1;
int arr01[N], segnums[N], segs[N];
int calc(int pos, int flag)
{
    int pos2 = pos + flag;
    if (abs(segnums[maxpos]-segnums[pos2]) * (flag > 0 ? segs[maxpos] : segs[pos2]) <= m)
    {
        return segs[pos2];
    }
    else
    {
        return 0;
    }
}
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int m2 = m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr01[i];
    }
    sort(arr01+1, arr01+n+1);
    int k = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (arr01[i] == arr01[i-1])
        {
            cnt++;
        }
        else
        {
            k++;
            segs[k] = cnt;
            segnums[k] = arr01[i-1];
            if (cnt > maxn)
            {
                maxn = cnt;
                maxpos = k;
            }
            cnt = 1;
        }
    }
    segs[++k] = cnt;
    segnums[k] = arr01[n];
    if (cnt > maxn)
    {
        maxn = cnt;
        maxpos = k;
    }
    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    int ans = maxn;
    int L = maxpos, R = maxpos;
    if (L == 1 && R == k)
    {
        cout << n << '\n';
        return 0;
    }
    while (true)
    {
        if (L == 1 && R == k) break;
        if (R == k)
        {
            int tmp = calc(L, -1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                segs[maxpos] += segs[L-1];
                L--;
            }
            else break;
        }
        else if (L == 1)
        {
            int tmp = calc(R, 1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                segnums[maxpos] = segnums[R+1];
                segs[maxpos] += segs[R+1];
                R++;
            }
            else break;
        }
        else
        {
            int tmp1 = calc(L, -1), tmp2 = calc(R, 1);
            if (tmp1 == 0 && tmp2 == 0) break;
            else
            {
                if (tmp1 <= tmp2)
                {
                    ans += tmp1;
                    m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                    segs[maxpos] += segs[L-1];
                    L--;
                }
                else
                {
                    ans += tmp2;
                    m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                    segnums[maxpos] = segnums[R+1];
                    segs[maxpos] += segs[R+1];
                    R++;
                }
            }
        }
    }
    if (R == k)
    {
        int tmp = m / (segnums[maxpos] - segnums[L-1]);
        ans += tmp;
    }
    else if (L == 1)
    {
        int tmp = m / (segnums[R+1] - segnums[maxpos]);
        ans += tmp;
    }
    else
    {
        int tmp1 = m / (segnums[R+1] - segnums[maxpos]), tmp2 = m / (segnums[maxpos] - segnums[L-1]);
        ans += max(tmp1, tmp2);
    }
    ans1 = ans;
    ans = maxn;
    L = maxpos, R = maxpos;
    m = m2;
    while (true)
    {
        if (L == 1 && R == k) break;
        if (R == k)
        {
            int tmp = calc(L, -1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                segs[maxpos] += segs[L-1];
                L--;
            }
            else break;
        }
        else if (L == 1)
        {
            int tmp = calc(R, 1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                segnums[maxpos] = segnums[R+1];
                segs[maxpos] += segs[R+1];
                R++;
            }
            else break;
        }
        else
        {
            int tmp1 = calc(L, -1), tmp2 = calc(R, 1);
            if (tmp1 == 0 && tmp2 == 0) break;
            else
            {
                if (tmp1 < tmp2)
                {
                    ans += tmp1;
                    m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                    segs[maxpos] += segs[L-1];
                    L--;
                }
                else
                {
                    ans += tmp2;
                    m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                    segnums[maxpos] = segnums[R+1];
                    segs[maxpos] += segs[R+1];
                    R++;
                }
            }
        }
    }
    if (R == k)
    {
        int tmp = m / (segnums[maxpos] - segnums[L-1]);
        ans += tmp;
    }
    else if (L == 1)
    {
        int tmp = m / (segnums[R+1] - segnums[maxpos]);
        ans += tmp;
    }
    else
    {
        int tmp1 = m / (segnums[R+1] - segnums[maxpos]), tmp2 = m / (segnums[maxpos] - segnums[L-1]);
        ans += max(tmp1, tmp2);
    }
    ans2 = ans;
    ans = maxn;
    L = maxpos, R = maxpos;
    m = m2;
    while (true)
    {
        if (L == 1 && R == k) break;
        if (R == k)
        {
            int tmp = calc(L, -1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                segs[maxpos] += segs[L-1];
                L--;
            }
            else break;
        }
        else if (L == 1)
        {
            int tmp = calc(R, 1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                segnums[maxpos] = segnums[R+1];
                segs[maxpos] += segs[R+1];
                R++;
            }
            else break;
        }
        else
        {
            int tmp1 = calc(L, -1), tmp2 = calc(R, 1);
            if (tmp1 == 0 && tmp2 == 0) break;
            else
            {
                if (tmp1 < tmp2)
                {
                    ans += tmp1;
                    m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                    segs[maxpos] += segs[L-1];
                    L--;
                }
                else
                {
                    ans += tmp2;
                    m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                    segnums[maxpos] = segnums[R+1];
                    segs[maxpos] += segs[R+1];
                    R++;
                }
            }
        }
    }
    if (R == k)
    {
        int tmp = m / (segnums[maxpos] - segnums[L-1]);
        ans += tmp;
    }
    else if (L == 1)
    {
        int tmp = m / (segnums[R+1] - segnums[maxpos]);
        ans += tmp;
    }
    else
    {
        int tmp1 = m / (segnums[R+1] - segnums[maxpos]), tmp2 = m / (segnums[maxpos] - segnums[L-1]);
        ans += max(tmp1, tmp2);
    }
    ans3 = ans;
    ans = maxn;
    L = maxpos, R = maxpos;
    m = m2;
    while (true)
    {
        if (L == 1 && R == k) break;
        if (R == k)
        {
            int tmp = calc(L, -1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                segs[maxpos] += segs[L-1];
                L--;
            }
            else break;
        }
        else if (L == 1)
        {
            int tmp = calc(R, 1);
            if (tmp)
            {
                ans += tmp;
                m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                segnums[maxpos] = segnums[R+1];
                segs[maxpos] += segs[R+1];
                R++;
            }
            else break;
        }
        else
        {
            int tmp1 = calc(L, -1), tmp2 = calc(R, 1);
            if (tmp1 == 0 && tmp2 == 0) break;
            else
            {
                if (tmp1 < tmp2)
                {
                    ans += tmp1;
                    m -= (segnums[maxpos] - segnums[L-1]) * (segs[L-1]);
                    segs[maxpos] += segs[L-1];
                    L--;
                }
                else
                {
                    ans += tmp2;
                    m -= (segnums[R+1] - segnums[maxpos]) * (segs[maxpos]);
                    segnums[maxpos] = segnums[R+1];
                    segs[maxpos] += segs[R+1];
                    R++;
                }
            }
        }
    }
    if (R == k)
    {
        int tmp = m / (segnums[maxpos] - segnums[L-1]);
        ans += tmp;
    }
    else if (L == 1)
    {
        int tmp = m / (segnums[R+1] - segnums[maxpos]);
        ans += tmp;
    }
    else
    {
        int tmp1 = m / (segnums[R+1] - segnums[maxpos]), tmp2 = m / (segnums[maxpos] - segnums[L-1]);
        ans += max(tmp1, tmp2);
    }
    ans4 = ans;
    cout << max(max(ans3, ans4), max(ans1, ans2)) << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
