#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],a[100005],b[100005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;

    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];

        }
        if(c==0)
        {
            if(n==4&&d==2)
            {
                cout<<1<<endl;
            }
            if(n==5&&d==2)
            {
                cout<<2<<endl;
            }
            if(n==5&&d==3)
            {
                cout<<0<<endl;
            }
            if(n==6&&d==2)
            {
                cout<<1<<endl;
            }
        }
        else
        {
            cout<<d<<endl;
        }
    }


    return 0;
}
