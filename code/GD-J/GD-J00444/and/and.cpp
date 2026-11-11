#include<bits/stdc++.h>
using namespace std;
long long n,m,a[210000],w[64],s,z;
bitset <210000> b[64],dn,x;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    w[0]=1;
    dn[0]=true;
    for(long long i=1;i<=31;i++)
    {
        w[i]=w[i-1]*2;
    }
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        dn[i]=true;
        cin>>a[i];
        for(long long j=31;j>=0;j--)
        {
            if((a[i]&w[j])!=0)
            {
                b[j][i]=true;
            }
        }
    }
    for(long long i=31;i>=0;i--)
    {
        x=dn&b[i];
        z=x.count();
        if(z>=m)
        {
            s+=w[i];
            dn=x;
        }
    }
    cout<<s;
    return 0;
}
