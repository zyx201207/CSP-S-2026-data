#include<bits/stdc++.h>
using namespace std;
long long x[2000005];
int main()
{
 freopen("migrate.in","r",stdin);
 freopen("migrate.out","w",stdout);
    long long n=5,c,t,d,cnt=0;
    cin>>c>>t;
    for(int o=1;o<=t;o++)
    {
        cnt=0;
        for(long long i=1;i<=n;i++)
        {
            x[i]=-1;
        }
    cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
            if(x[i]-x[i-1]>d)
            {
                x[i]=-1;
                n=i-1;
                break;
            }
        }
        for(long long i=3;i<=n;i++)
        {
            for(long long j=1;j<=i;j++)
            {
                if((x[i]-x[j])/d==1&&(x[i]-x[j])%d==d-1)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
