#include<iostream>
using namespace std;
long long x[2000005];

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            long long n,d;
            cin>>n>>d;
            for(int i=1;i<=n;i++)
            {
                cin>>x[i];

            }
            long long b=d/(x[2]-x[1]);
            if(b<2)
            {
                cout<<0<<endl;
                continue;
            }
            cout<<max(n-2*b+1,0*n)<<endl;
        }
    }
    else
    {
        while(t--)cout<<0<<endl;
    }
}
/*
mo3xie3jin1ke0la1ge1ci2de4ren2 love lyx
*/
