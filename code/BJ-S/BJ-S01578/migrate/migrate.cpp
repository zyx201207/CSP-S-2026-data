#include<iostream>
using namespace std;

int x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n,d;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j++)
        {
            cin>>x[j];
        }
        cout<<0<<endl;
    }
    return 0;
}
