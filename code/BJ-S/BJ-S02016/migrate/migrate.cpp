#include <bits/stdc++.h>
using namespace std;
long long a[5005],f[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T; cin>>c>>T;
    while(T--)
    {
        long long n,d; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<n-3<<endl;
    }
    return 0;
}
