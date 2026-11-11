#include<bits/stdc++.h>
using namespace std;
int n, cnt;
long long m, a[500010];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int c = a[2] - a[1];
    for(int i = 1; i <= n; i++)
    {
        cnt++;
        m -= i*c;
        if(m < 0)
        {
            break;
        }
    }
    cout << cnt;
    return 0;
}
