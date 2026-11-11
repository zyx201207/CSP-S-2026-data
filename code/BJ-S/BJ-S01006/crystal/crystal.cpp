#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

struct cry
{
    ll size;
    int num;
};

ll a[500005];
cry c[500005];

int n;
ull m;
int cnt = 0;

bool fa = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] != i)
        {
            fa = 0;
        }
    }
    if(fa)
    {
        cout << min((ll)n,(ll)((1 + sqrt(1 + 8 * m)) / 2)) << '\n';
        return 0;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++)
    {
        cnt++;
        c[cnt].size = a[i];
        int j = i;
        while(a[j] == a[i] && j <= n)
        {
            c[cnt].num++;
            j++;
        }
        i = j - 1;
    }
    int maxn = 0;
    for(int i = 1;i <= cnt;i++)
    {
        int x = c[i].num;
        ull mm = m;
        for(int j = i - 1;j >= 1 && mm >= c[i].size - c[j].size;j--)
        {
            int t = min(mm / (c[i].size - c[j].size),(ull)c[j].num);
            mm -= (c[i].size - c[j].size) * t;
            x += t;
        }
        maxn = max(maxn,x);
    }
    cout << maxn << endl;
    return 0;
}
