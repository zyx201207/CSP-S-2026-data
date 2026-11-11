#include <bits/stdc++.h>
using namespace std;
long long a[30000050] = {};
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,su = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    su = a[n];
    for(int j = (n - 1);j > (n - m);j--)
    {
        su = su & a[j];
    }
    cout<<su;
    return 0;
}
