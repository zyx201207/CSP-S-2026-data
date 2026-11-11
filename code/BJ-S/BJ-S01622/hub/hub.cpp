#include <iostream>
using namespace std;

int c , t , n , k;

int main()
{
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    cin >> c >> t;
    if (c == 13 || c == 14)
    {
        cin >> n >> k;
        cout << (((n - 1) / 2 + 1) / 2 - (k - 1) / 2 + 1) / 2 << endl;
    }
    return 0;
}
