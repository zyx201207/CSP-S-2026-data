#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int cnt = 0,j = 0;
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < m; i++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > cnt)
            {
                cnt = a[i];
                j = i;
            }
        }
        a[j] = 0;
        cnt = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > cnt)
        {
            cnt = a[i];
        }
    }
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}