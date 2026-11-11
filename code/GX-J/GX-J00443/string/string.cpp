#include<bits/stdc++.h>
using namespace std;
string cnt[10000005],a[10000005],c[10000005];
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0,d,y=0,ctn=0,b=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        cin>>cnt[y];
        for(int q=0;q<d;q++)
        {
            cnt[y+1]=cnt[y];
            a[y]=cnt[y];
            y++;
            b++;
        }
        sum+=d;
    }
    d=y;
    y=0;
    for(int i=d-1;i>=0;i--)
    {
        a[i]=cnt[y];
        y++;
    }
    sum/=2;
    for(int j=0;j<y;j++)
    {
        if(a[j+sum]!=cnt[j+sum])
        {
            ctn++;
        }
    }
        ctn--;
    cout<<ctn;
    return 0;
}
