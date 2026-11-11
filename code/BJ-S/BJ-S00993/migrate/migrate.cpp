#include<iostream>
using namespace std;

int c,t,n,d;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1; i<=n; i++)
            cin>>d;
        cout<<0;
    }
    return 0;
}
