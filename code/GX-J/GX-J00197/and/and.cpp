#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx = -1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            if (i != j)maxx = max(maxx,a[i]&a[j]);
    cout << maxx;
    return 0;
}
