#include<iostream>
using namespace std;
long long c,t,n,d,a[2000005],k;
int main()//8pts
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        a[n+1]=a[n];
        if(1)//8pts
        {
            k=a[2]-a[1];
            d/=k;
            if(d<=1)
            {
                cout<<"0\n";
                continue;
            }
            d<<=1;
            if(d>n)
            {
                cout<<"0\n";
                continue;
            }
            d=n-d+1;
            cout<<d<<"\n";
        }
    }
    return 0;
}
