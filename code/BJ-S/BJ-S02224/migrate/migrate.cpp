#include <iostream>
using namespace std;

long long c , t , n , d , a[100010][200010];

int main()
{
    cin >> c >> t;
    for(int i = 1;i <= t;i++)
    {
        cin >> n >> d;
        long long ans = 0;
        for(int j = 1;j <= n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] - a[i][1] > 2 * d && a[i][j - 1] - a[i][1] <= 2 * d)
            {
                ans = n - j;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}