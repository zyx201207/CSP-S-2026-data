#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long num = 0;
    char zifu;
};

node a[200010];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].num >>a[i].zifu;
    }
    long long ans = 0;
    long long last = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].num == 0)
        {
            continue;
        }
        while (a[i].num != 0)
        {
            //cout << a[i].num << " " << a[last].num << ans << endl;
            if (a[last].num <= a[i].num)
            {
                a[i].num -= a[last].num;
                if (a[i].zifu != a[last].zifu)
                {
                    ans += a[last].num;
                }
                a[last].num = 0;
                last--;
            }
            else{
                if (a[i].zifu != a[last].zifu)
                {
                    ans += a[i].num;
                }
                a[last].num -= a[i].num;
                a[i].num = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
