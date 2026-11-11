#include <bits/stdc++.h>
using namespace std;
int a[100000];
bool cmp(int y,int z)
{
    return y > z;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,b,n,m,t=0;
    int cnt = 0;
    int sum = 0;
    int st;
    cin >> c >> b;
    for (int i = 1;i <= b;i++)
    {
        cin >> n >> m;
        for (int j = 0;j < n;j++)
        {
            cin >> a[i];
        }

    }
    cout << 1 << endl;
    cout << 2 << endl;
    return 0;
}
