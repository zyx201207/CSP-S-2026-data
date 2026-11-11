#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long a[500005];
long long s[500005];
int box[205];
int ans = 1;

bool cmp(long long x, long long y)
{
    return x < y;
}

int main()
{
    int n;
    long long m;
    cin >> n;
    cin >> m;
    bool flag1 = true;
    bool flag2 = true;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if (a[i] != i)
        {
            flag1 = false;
        }
        if (a[i] > 100)
        {

            flag2 = false;
        }
    }
    sort (a + 1, a + 1 + n, cmp);
    if (flag1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (m < (i * (i - 1)) / 2)
            {
                cout << i - 1 << endl;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    if (n <= 5000)
    {
        for (int i = 1; i <= n; i++)
        {
            s[i] = a[i] - a[i - 1];
        }
        for (int i = 2; i <= n; i++)
        {
            long long temp = m;
            int len = 1;
            while (temp >= s[i - len + 1] * len && len <= i)
            {
                temp -= s[i - len + 1] * len;
                len++;
            }
            ans = max(ans, len);
        }
        cout << ans << endl;
        return 0;
    }
    if (flag2)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] += 101;
            box[a[i]]++;
        }
        for (int i = 1; i <= 201; i++)
        {
            int temp = box[i];
            int cha = 1;
            long long tempm = m;
            while (true)
            {
                if (i - cha >= 1 && tempm >= box[i - cha] * cha)
                {
                    tempm -= box[i - cha] * cha;
                    temp += box[i - cha];
                }
                else
                {
                    if (i - cha >= 1)
                    {
                        temp += tempm / cha;
                        tempm -= (tempm / cha) * cha;
                    }
                    break;
                }
                cha++;
            }
            ans = max(ans, temp);
        }
        cout << ans << endl;
        return 0;
    }
    long long gc = a[2] - a[1];
    long long scm = m / gc;
    for (int i = 1; i <= n; i++)
    {
        if (scm < (i * (i - 1)) / 2)
        {
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n;
    return 0;
}
