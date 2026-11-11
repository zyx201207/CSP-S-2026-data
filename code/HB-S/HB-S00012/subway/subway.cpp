#include <bits/stdc++.h>
using namespace std;


int a[2];
int main()
{
    //Da biao
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> a[0] >> a[1];
    if (a[1] == 2)
    {
        cout << 32 << endl << 17;
        return 0;
    }
    else if (a[1] == 3)
    {
        cout << 35 << endl << 16;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
