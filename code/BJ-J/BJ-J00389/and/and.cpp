#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n, m;
int dg(int i, int nownum, int nowans)
{
    if(nownum == m) return nowans;
    if(n - i + nownum < m) return 0;
    nowans = max(dg(i + 1, nownum, nowans), dg(i + 1, nownum + 1, nowans & a[i]));
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << dg(0, 0, pow(2, 31) - 1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
