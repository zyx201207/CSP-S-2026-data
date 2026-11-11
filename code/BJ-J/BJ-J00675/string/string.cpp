#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,num,ans;
int a[200005];
char c[200005];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i] >> c[i];
    }
    int i=1, j=n;
    while(i < j)
    {
        if(a[i] == a[j])
        {
            if(c[i] != c[j])
            {
                ans += a[i];
            }
            a[i] = 0;
            a[j] = 0;
            i++;
            j--;
        }
        else if(a[i] > a[j])
        {
            if(c[i] != c[j])
            {
                ans += a[j];
            }
            a[i] -= a[j];
            a[j] = 0;
            j--;
            /*
            cout << i << ' ' << j << "     ";
            for(int b=1; b<=n; b++)
            {
                cout << a[b] << ' ';
            }
            cout << "     " << ans;
            cout << endl;
            */
        }
        else
        {
            if(c[i] != c[j])
            {
                ans += a[i];
            }
            a[j] -= a[i];
            a[i] = 0;
            i++;
        }

    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
