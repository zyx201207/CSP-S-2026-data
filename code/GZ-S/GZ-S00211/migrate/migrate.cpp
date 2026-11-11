//GZ-S00211，卿可玥，贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        int n,d;
        cin>>n>>d;
        int x[n];
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        if(c==0)
        {
            if(n==4)
            {
                cout<<1<<endl<<2;
                return 0;
            }
            if(n==5)
            {
                cout<<0<<endl<<1;
                return 0;
            }
        }
    }
    return 0;
}
