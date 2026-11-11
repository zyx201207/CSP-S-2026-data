#include <iostream>
using namespace std;

int x[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >>t;
    while(t--)
    {
        int n,d;
        cin >>n >>d;
        for (int i = 1; i <= n; i++)
        {
            cin >>x[i];
        }
        if (n % d == 0)
        {
            cout << (1 + n / d + 1) * (n / d - 1) /2<<endl;
        }
    }
    return 0;
}
