#include <bits/stdc++.h>
using namespace std;
int iis = 1,n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long m,ans;
    long long aq[10000005];
    string ap[10000005];
    string paee;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> m >> paee;
        aq[i] = m;
        ap[i] = paee;
    }
    while(iis != n)
    {
        cout << "t";
        if (ap[iis] != ap[n])
        {
            if (aq[iis] != 0 && aq[n] != 0)
            {
                int uut = min(aq[iis],aq[n]);
                aq[iis] -= uut;
                aq[n] -= uut;
                ans += uut;
            }
            else
            {
                if (aq[iis] == 0)
                    iis++;
                if (aq[n] == 0)
                    n--;
            }
        }
        else
        {
            int uut = min(aq[iis],aq[n]);
            aq[iis] -= uut;
            aq[n] -= uut;
        }
    }
    cout << ans;
    return 0;
}
