#include <bits/stdc++.h>
using namespace std;

int a[200001];

int main()
{
    freopen("and.in","r",std);
    freopen("and.out","w",std);
    int m,n,maxn = 0;
    cin >> m>> n;
    if(m==1)
    {
        while(n--)
        {
            int x;
            cin >> x;
            maxn = max(maxn,x);
        }
        cout << maxn;
        return 0;
    }
    if(m==n)
    {
        int x;
        cin >> x;
        maxn = x;
        for(int i = 1;i<n;i++)
        {
            int y;
            cin >> y;
            maxn = maxn&y;
        }
        cout << maxn;
        return 0;
    }
    for(int i = 0;i<n;i++)
    {
        cin >>a[i];
    }
    for(int i = 0;i<=n-m;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            maxn = max(maxn,k);
        }
    }
    cout << maxn;
}