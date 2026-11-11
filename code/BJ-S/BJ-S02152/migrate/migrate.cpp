#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long d;
        cin>>n>>d;
        long long a[N];
        int cha;
        for(int i=1;i<=n;i++)
        {
            long long s;
            cin>>s;
            long long l=s;
            cha=s-l;
            a[i]=s;
        }
        cha=a[2]-a[1];
        int hg;
        if(cha==d) cout<<0<<endl;
        else if(d>cha)
        {
            if(d%cha==0)
            {
                hg=d/cha;
                cout<<n-hg-1<<endl;
            }
            else
            {
                if(d<2*cha)
                {
                    cout<<0<<endl;
                }
                else
                {
                    hg=d/cha+2;
                    cout<<n-hg+1<<endl;
                }
            }
        }
        else cout<<0<<endl;
    }
    return 0;
}
