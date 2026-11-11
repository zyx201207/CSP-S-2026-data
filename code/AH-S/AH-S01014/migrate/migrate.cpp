#include<bits/extc++.h>
using namespace std;
long long n,T;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>T;
    while(T--)
    {
        long long m,a[200006];
        cin>>n>>m;
        if(n<=3)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=min(n,200ll);i++)
        {
            cin>>a[i];
        }
        if(a[3]-a[1]<=m && a[4]-a[1]>m) cout<<n-3<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
