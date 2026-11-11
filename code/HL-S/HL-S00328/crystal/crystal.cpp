#include<bits/stdc++.h>
using namespace std;
long long  n, m;
const int N = 1e6 + 3;
long long a[N];
int maxa = 1;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int a[100005];
    cin  >> n >> m;
    for (int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }
    sort (a + 1, a + n + 1);
    for (int i = 1 ; i <= n + 1 - maxa; i++)
    {
        int k = i;
        while(1)
        {
            if (k < n)
            {
                k++;
                m -= a[i] - a[k];
            }
            else
            {
                break;
            }
            if (m < 0);
            {
                k--;
                break;
            }
        }
        maxa = max(maxa, k - i + 1);
    }
    cout << maxa;
    return 0;
}
