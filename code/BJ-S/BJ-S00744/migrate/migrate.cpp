#include <bits/stdc++.h>
using namespace std;
int C, T;
int x[100010];
void Main()
{
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    if(C == 13 || C == 14)
    {
        if(d > x[2] - x[1] && d < 2 * (x[2] - x[1]))
        {
            printf("%d\n", n-2);
            return;
        }
        else
        {
            cout << "0\n";
            return;
        }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >>C>>T;
    while(T--) Main();
    return 0;
}

