#include<bits/stdc++.h>
using namespace std;
long long a[200005],c1[200005],b1[200005];
char c[200005],b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        c1[i]=c1[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=c[n-i+1];
        b1[i]=c1[n-i+1]-c1[n-i]+b1[i-1];
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<c[i]<<" "<<c1[i]<<endl;
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" "<<b1[i]<<endl;
    }*/
    long long c2=1,b2=1,x=0,m=c1[n];
    while(c2<=n||b2<=n)
    {

        if(c1[c2]>b1[b2])
        {
            if(c[c2]!=b[b2])
            {
                sum+=b1[b2]-x;
            }
            x=b1[b2];
            b2++;
        }
        else if(c1[c2]<b1[b2])
        {
            if(c[c2]!=b[b2])
            {
                sum+=c1[c2]-x;
            }
            x=c1[c2];
            c2++;
        }
        else
        {
            if(c[c2]!=b[b2])
            {
                sum+=c1[c2]-x;
            }
            x=c1[c2];
            c2++;
            b2++;
        }
    }
    if(sum%2==0)
    {
        cout<<sum/2;
    }
    else
    {
        cout<<sum/2+1;
    }
    return 0;
}
