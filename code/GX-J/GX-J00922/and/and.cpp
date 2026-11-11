#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[1000001],p=1,q=1,er,er1,er2;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int w=1;;w*=10)
            {
                er+=b[j]%2*w;
                b[i]/=2;
                q*=10;
                if(b[i]==0)
                {
                    break;
                }
            }
            for(int w=1;;w*=10)
            {
                er1+=b[j]%2*w;
                b[i]/=2;
                p*=10;
                if(b[i]==0)
                {
                    break;
                }
            }
            if(q<p) q=p;
            for(int w=1;w<=q;w*=10)
            {
                if(er/w%10==er1)
                {
                    er2+=w;
                }
            }
        }
    }
    cout <<er2;
    return 0;
}
