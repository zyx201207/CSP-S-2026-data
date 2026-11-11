#include <iostream>
using namespace std;
long long x[26];
int main()
{
    ios::sync_with_stdio(false);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i = 1;i <= c;i++)
    {
        cin >> x[i];
    }
    cout << c * (c - 1) << endl;
    return 0;
}
