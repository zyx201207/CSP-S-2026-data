#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
long long n,m,a[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[(n+1)/2];
    return 0;
}
