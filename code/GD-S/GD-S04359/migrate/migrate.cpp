#include <bits/stdc++.h>
#define cin in
#define cout out
using namespace std;
ifstream in("migrate.in");
ofstream out("migrate.out");
long long c = 0, t = 0;
long long x[1000];
int main()
{
    cin >> c >> t;
    long long n = 0, d = 0;
    long long addd = 0;
    for (long long qwertyuiop = 0; qwertyuiop < t; qwertyuiop++)
    {

        n = 0, d = 0;
        addd = 0;
        cin >> n >> d;
        for (long long i = 0; i <= n; i++)
        {
            cin >> x[i];
        }

        for (long long i0 = 0; i0 <= n; i0++)
        {
            for (long long i1 = i1; i1 <= i0; i1++)
            {
                for (long long i2 = n; i2 >= i1; i2--)
                {

                    if ((x[i1 + 2] - x[i1] == x[i1 + 3] - x[i1 + 1]))
                    {
                        addd++;
                    }
                }
            }
        }
        cout << addd << "\n";
    }

    // cout << "1\n2 ";
}
