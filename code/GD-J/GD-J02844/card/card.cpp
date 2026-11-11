#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


long long a[500009];
long long int ct[300009];
int n,m;
int v[500009];
int vsize = 0;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for (int jj = 1; jj <= n;jj++)
    {

        for (int k = jj;k <= n;k++)
        {
            for (int x = 0;x < vsize;x++)
            {
                if (v[x] == a[k])
                {
                    vsize = x;
                    break;
                }
            }
            v[vsize++]=a[k];
        }
        for (int i = 0;i < vsize;i++)
        {
            if (v[i] <= m)
            {
                ct[v[i]]++;
            }
        }
        vsize = 0;
    }
    for (int i = 1;i <= m;i++)
    {

        cout << ct[i] << " ";
    }
    return 0;
}
