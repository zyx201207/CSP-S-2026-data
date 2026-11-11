#include <bits/stdc++.h>
using namespace std;
long long a[200001],maxa=-1;
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (a[i]&a[j]>maxa)
            {
                maxa=a[i]&a[j];
            }
        }
    }
    cout << maxa;
}