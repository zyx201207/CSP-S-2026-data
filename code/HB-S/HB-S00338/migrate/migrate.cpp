#include <bits/stdc++.h>
using namespace std;

int c,t,n;
long long d,ch,x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
            cin >> x[i];
        ch = x[2]-x[1];
        if(d < 2*ch)
        {
            cout << 0 << endl;
            continue;
        }
        long long num = d/ch*2;
        if(num <= n)
            cout << n-num+1 << endl;
        else
            cout << 0 << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
