#include<bits/stdc++.h>
using namespace std;
int a[100000000];
int b[100000000];
int c[100000000];
int q=0,z=0;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int o,x;
    cin>>c>>t;
    for(int i=0;i<t;t++)
    {
        cin>>o>>x;
        for(int p=0;p<o;p++)
        {
            cin>>b[p];
        }
        while(b[z]-b[q]>>x&&b[z]-b[q]<<2*x)
        {
            a[i]++;
            z++;
            if(z==o||b[z]-b[q]>=2*z)
            {
                q++;
                z=0;
            }
            if(q==o)
            {
                break;
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<a[i];
    }
    return 0;
}
