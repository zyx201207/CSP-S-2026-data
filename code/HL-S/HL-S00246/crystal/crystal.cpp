#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x < y;
}
int a[1000000];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen ("crystal.out","w",stdout);
    int n,m;
    int cnt = 0;
    int cnt2;
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        cin >> a[i];

        if (a[i] == a[i-1])
        {
            cnt++;

        }




    }
    cnt2 = n / 2+1+cnt;
    cout << cnt2;

    return 0;
}
