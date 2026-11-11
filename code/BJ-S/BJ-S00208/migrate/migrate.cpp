#include<bits/stdc++.h>
using namespace std;

long long x[2000010];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin >> c >> t;

    while(t--)
    {
        int n,d;
        cin >> n >> d;
        int fl = 1;
        for(int i = 1;i <= n;i++)
        {
            cin >> x[i];
            if(x[i] - x[i - 1] != x[i - 1] - x[i - 2]) fl = 0;
        }


        if(fl == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        int ans = 1;
        for(int i = 1;i <= n;i++)
        {
            if((x[i] + d) >= x[i + 2])
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
