#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    int a[n];
    int b[m+1] = {0};
    for(int i = 0;i < n;i++)
        cin >> a[i];

    for(int i = 0;i < n;i++)
    {
        int s[m+1] = {0};
        int l = -1;
        int zt[m+1] = {0};
        for(int j = i;j < n;j++)
        {
            l++;
            s[l] = a[j];

            int x = a[j];
            zt[x]++;
            if(zt[x] == 2)
            {

                for(;l >= 0;l--)
                {
                    zt[s[l]]--;
                    s[l] = 0;
                    if(s[l-1] == a[j])
                        break;
                }
            }
        }
        for(int i = 1;i <= m;i++)
            if(zt[i] > 0)
                b[i]++;
    }

    for(int i = 1;i <= m;i++)
        cout << b[i] << " ";
    return 0;
}
