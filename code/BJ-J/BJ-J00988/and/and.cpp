#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200010;
int a[N];

bool cmp(int x, int y)
{
    int dx[31], dy[31];
    int i = 1, ax = 0, ay = 0;
    while(x > 1)
    {
        dx[i] = x % 2;
        x /= 2;
        i++;
        if(dx[i] == 0)
        {
            ax++;
        }
    }
    i = 0;
     while(y > 1)
    {
        dy[i] = y % 2;
        y /= 2;
        i++;
        if(dy[i] == 0)
        {
            ay++;
        }
    }

    if(ax > ay)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);

    int ans = a[1];
    for(int i = 2; i <= m; i++)
    {
        ans = ans & a[i];

    }
    cout << ans << endl;
    return 0;
}
