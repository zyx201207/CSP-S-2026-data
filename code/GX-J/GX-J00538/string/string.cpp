#include <bits/stdc++.h>
using namespace std;

long long n, dn=0, b=0,zs=0;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long m[1000000];
    if(n==1||n==0)
    {
        cout<<"0";
    }
    else
    {
        for(long long i=1;i<=n;i++)
        {
            cin>>b;
            zs+=b;
            cin>>c;
            for(long long j=1;j<=b;j++)
            {
                m[j]=c;
            }
        }
        for(long long i=1;i<=zs/2;i++)
        {
            if(m[i]!=m[zs-i+1])
            {
                dn++;
            }

        }
        cout<<dn;
    }
}
