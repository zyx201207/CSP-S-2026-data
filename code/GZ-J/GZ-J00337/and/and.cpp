//GZ-J00337黄寅轩观山湖区华润中学
#include <bits/stdc++.h>
using namespace std;

int n, m;
int ms[200005], ms2[200005], lms, jlms1, jlms2;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &ms[i]);
    }
    if (m == 1)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            if (ms[i] < ms[i + 1])
            {
                jlms2 = ms[i + 1];
                return 0;
            }
        }

    }
    if (m == 2)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= n - 1;j++)
            jlms1 = ms[i]^ms[i + j];
        }
        if (jlms1 > jlms2)
        {
            jlms2 = jlms1;
        }
    }
    else
    {
        for (int i = 1; i <= n - m; i++)
        {
            for (int l = 1; l <= m - 1; l++)
            {
                for (int j = 1; j <= n - 1; j++)
                {
                    jlms1 = ms[i]^ms[i + j];
                }
                lms = ms[i]^ms[i + m - 1];
            }
            if (jlms1 > jlms2)
                {
                    jlms2 = jlms1;
                }
        }
    }
    cout << jlms2 ;
return 0;
}
