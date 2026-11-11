#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long qzh[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,cnt=0;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
if(a[2]-a[1]==a[3]-a[2]==a[5]-a[4]==a[4]-a[3])
{
    int i=1;
    while(m>0)
    {
        if( m>=i*(a[2]-a[1]))
        {
             m-=i*(a[2]-a[1]);
        i++;
        }
       else
        break;
    }
    cout<<i;
    return 0;
}
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
        for(int x=0;x<j;x++)
        {
            qzh[j]=a[i+1]-a[j]+qzh[j-1];
             if(qzh[j]-qzh[x]<=m)
           {
               cnt=max(cnt,j-x+1);
           }

        }
        }
    }
    cout<<cnt;
    return 0;
}
