#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,i,j,d,cnt;
    cin >> n >> i >> j >> d;
    for(int i=1; i<=n; i++)
    {

        if(i-j<=d)
        {

            cnt++;
        }
    }
    cout << cnt;


    return 0;
}
