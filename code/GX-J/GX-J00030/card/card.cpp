#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],c[200001];
long long n,m,s;
long long mn(long long x)
{
    long long i,j;
    for(i=x;i<=n;++i)
    {
        s++;
        b[s]=a[i];
        j=1;
        while(b[j]!=a[i]&&j<s)
            j++;
        if(j<s) s=j;
    }
   // for(i=1;i<=s;++i)
        //cout<<b[i]<<"  ";
    //cout<<endl;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=s;++j)
        {
        if(b[j]==a[i]) c[a[i]]++;
        }
    }
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long i,j,sh=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        {cin>>a[i];}
    for(i=1;i<=n;++i)
    {
        s=0;
        for(j=i;j<=n;++j)
        { s++; b[s]=a[i];}
        mn(i);
    }
    for(i=1;i<=n;++i)
        if(c[i]>0) sh++;
    for(i=1;i<=sh;++i)
        cout<<c[i]<<" ";
    return 0;
}
