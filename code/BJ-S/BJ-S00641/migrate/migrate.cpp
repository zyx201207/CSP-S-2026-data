#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        d/=a[2]-a[1];
        long long cnt=0;
        if(d==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=d+1;i<=2*d-1;i++)
            cnt+=n-i;
        cout<<cnt<<endl;
    }
    return 0;
}
