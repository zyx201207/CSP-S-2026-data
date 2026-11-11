#include <bits/stdc++.h>
using namespace std;

struct nas
{
    long long n;
    char s;
};

int num[200005];
char str[200005];

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long l = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        l += num[i];
        cin >> str[i];
    }
    queue<nas> num_1;
    stack<nas> num_2;
    if (l % 2 == 0)
    {
        long long now = 0;
        int i = 1;
        while (now + num[i] <= l / 2)
        {
            num_1.push({num[i], str[i]});
            now += num[i];
            i++;
        }
        if (now < l / 2)
        {
            num_1.push({l / 2 - now, str[i]});
            num_2.push({num[i] - l / 2, str[i]});
            i++;
        }

        while (i <= n)
        {
            num_2.push({num[i], str[i]});
            i++;
        }
    }
    else
    {
        long long now = 0;
        int i = 1;
        while (now + num[i] <= l / 2)
        {
            num_1.push({num[i], str[i]});
            now += num[i];
            i++;
        }
        int i1 = 1;
        if (now < l / 2)
        {
            num_1.push({l / 2 - now, str[i]});
            num_2.push({num[i] - l / 2 - 1, str[i]});
            i1++;
            i++;
        }

        while (i <= n)
        {
            if (i1 == 1)
            {
                num_2.push({num[i] - 1, str[i]});
                i++;
            }
            else
            {
                num_2.push({num[i], str[i]});
                i++;
            }
        }
    }

    // check
    long long ans = 0;
    while (!num_1.empty())
    {
        if (num_1.front().n == num_2.top().n)
        {
            if (num_1.front().s == num_2.top().s)
            {
                num_1.pop();
                num_2.pop();
            }
            else
            {
                ans += num_1.front().n;
                num_1.pop();
                num_2.pop();
            }
        }
        else if (num_1.front().n > num_2.top().n)
        {
            int f = num_1.front().n;
            char fs = num_1.front().s;
            int s = num_2.top().n;
            char ss = num_2.top().s;
            num_1.front().n -= s;
            if (fs == ss)
            {
                num_1.pop();
                num_2.pop();
            }
            else
            {
                ans += f - s;
                num_1.pop();
                num_2.pop();
            }
        }
        else
        {
            int f = num_1.front().n;
            char fs = num_1.front().s;
            int s = num_2.top().n;
            char ss = num_2.top().s;
            num_2.top().n -= f;
            if (fs == ss)
            {
                num_1.pop();
                num_2.pop();
            }
            else
            {
                ans += f - s;
                num_1.pop();
                num_2.pop();
            }
        }
    }
    cout << ans;

    return 0;
}
