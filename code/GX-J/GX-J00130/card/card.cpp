#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[10000000];
bool bj[10000000];
long long mm[10000000];

int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int  i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if  (bj[a[i]] == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    a[i] = 0;
                }
            }
            else
            {
                bj[a[i]] = 1;
            }
        }
            for (int i = 0; i < n; i++)
            {
                if (bj[a[i]] == 1)
                {
                    mm[a[i]] += 1;
                }
            }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << mm[i] << " ";
    }
    return 0;
}
