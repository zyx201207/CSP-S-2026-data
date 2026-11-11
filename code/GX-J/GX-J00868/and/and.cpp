#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10005];
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        cin>> a[i];
    }
    sort(a+1,a+n+1);
    int c = a[n],b = n-1;
    for(int i = 1;i<m;i++)
    {
        c = c & a[b];
        b--;
    }
    cout<<c;
    return 0;
}
