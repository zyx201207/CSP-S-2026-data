#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long a[N] ,rjz[N][35] ,ans;
int n ,m ,sw[35];
vector <int> hzi[35] ,fiv;

long long getans (int deep)
{
    int canuse = 0;
    vector <int> tdv;
    for (int i = 1 ,j = 1;i <= hzi[deep].size() && j <= fiv.size(); )
    {
        if (hzi[deep][i] > fiv[j]) i++;
        else if ((hzi[deep][i] == fiv[j]))
        {
            tdv.push_back(i);
            i++ ;j++;
        }
        else j++;
    }
    if (tdv.size() >= m)
    {
        fiv = tdv;
        return (2 << deep) + getans(deep - 1);
    }
    return (deep - 1);
}

int main ()
{
    freopen ("and.in" ,"r" ,stdin);
    freopen ("and.out" ,"w" ,stdout);
    scanf ("%d%d" ,&n ,&m);
    for (int i = 1;i <= n;i++)
    {
        scanf ("%lld" ,&a[i]);
        //转化为二进制
        for (int j = 0;j <= 30;j++)
        {
            rjz[i][j] = (a[i] >> j) % 2;
            if (rjz[i][j])
            {
                sw[j]++;
                hzi[j].push_back(i);
            }
        }
        //for (int j = 10;j >= 0;j--) printf ("%d" ,rjz[i][j]);
        //printf ("\n");
    }
    if (m == 2 && n <= 2000)
    {
        ans = -1;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i == j) continue;
                ans = max(ans ,a[i] & a[j]);
            }
        printf ("%d\n" ,ans);
        return 0;
    }
    if (m == n)
    {
        ans = a[1];
        for (int i = 2;i <= n;i++)
            ans &= a[i];
        printf ("%d\n" ,ans);
        return 0;
    }
    if (m == 1)
    {
        ans = -1;
        for (int i = 1;i <= n;i++)
            ans = max(ans ,a[i]);
        printf ("%d\n" ,ans);
        return 0;
    }
    bool flag = true;
    for (int i = 0;i <= 30;i++)
        if (sw[i] >= m) flag = false;
    if (flag)
    {
        printf ("0\n");
        return 0;
    }
    //正解：
    int maxw = 31;
    while (sw[maxw] < m && maxw > -1) maxw--;
    if (maxw == -1)
    {
        printf ("0\n");
        return 0;
    }
    fiv = hzi[maxw];
    ans = getans (maxw);
    printf ("%lld\n" ,ans);
    return 0;
}
