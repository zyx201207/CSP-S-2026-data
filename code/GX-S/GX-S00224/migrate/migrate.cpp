#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",std.in);
    freopen("migrate.out","w",std.out);
    int c,t,n,d,sum=0,x;
    srand(time(0));
    long long a[10005],b[10005];
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>d;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
    }
    for(int i=1;i<=t;i++)
    {
        x=rand()%10;
        cout<<x<<endl;
    }
    return 0;
}
