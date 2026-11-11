#include <iostream>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
long long a[2000010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12||c==0)
    {
        while(t--)
        {
            long long d;
            int n;
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            //cout<<a[2]-a[1]<<' '<<d<<endl;
            long long p=d/(a[2]-a[1]);
            if(p<=1)cout<<0<<endl;
            else cout<<max(n-2*p+1,0ll)<<endl;
        }


    }
}
