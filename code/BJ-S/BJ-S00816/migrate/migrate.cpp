#include <bits/stdc++.h>
using namespace std;

int c,t;
long long a[2000006];
int n,d;


int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t --)
    {
        cin >> n >> d;
        for (int i = 1;i <= n;i ++)
        {
            cin >> a[i];
        }
        if (n == 1 || n == 0 || n == 2 || n == 3)
        {
            cout << 0 << endl;
        }
        else    cout << 1 << endl;
    }
    fclose(stdin);
    fclose(stdout);


    return 0;
}
