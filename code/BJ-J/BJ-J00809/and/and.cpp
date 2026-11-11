#include<bits/stdc++.h>
using namespace std;
long long n,m,a1,a2,a3,a4=0,a5,a6,a7;
long long a[200005][35],b2[200005];
int b1(long long c1,long long ans,long long c2)//dijige,yiyoudeshu,yiyoujige
{
    long long d1,d2,d3,d4=0,an[35];
    if(c1==n)
    {
        return 0;
    }
    if(c2==0)
    {
        b1(c1+1,0,0);
        b1(c1+1,b2[c1],1);
    }
    else
    {
        b1(c1+1,ans,c2);
        d1=ans;
        d2=0;
        while(d1)
        {
            if(d1%2!=0)
            {
                an[d2]=1;
            }
            else
            {
                an[d2]=0;
            }
            d1=d1/2;
            d2++;
        }
        d3=1;
        for(a1=0;a1<a4;a1++)
        {
            if(a[c1][a1]==1&&an[a1]==1)
            {
                d4+=d3;
            }
            d3*=2;
        }
        c2++;
        if(c2==m)
        {
            if(d4>a5)
            {
                a5=d4;
//                cout<<c2<<" ";
            }
            return 0;
        }
        b1(c1+1,d4,c2);
    }
    return 0;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(a1=0;a1<n;a1++)
    {
        cin>>b2[a1];
        a2=b2[a1];
        a3=0;
        while(a2)
        {
            if(a2%2!=0)
            {
                a[a1][a3]=1;
            }
            a2/=2;
            a3++;
        }
        if(a3>a4)
        {
            a4=a3;
        }
 //       cout<<a4;
    }
//    cout<<a[0][0]<<a[0][1]<<a[0][2]<<a[0][3];
    b1(0,0,0);
    cout<<a5;
    return 0;
}
