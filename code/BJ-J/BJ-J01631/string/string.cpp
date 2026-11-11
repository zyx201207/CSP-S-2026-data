#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,w=0,m=0,cnt=0;
    int a[1000005],b[1000005],c[1000005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w;
        cin>>m;
        for(int j=1;j<=w;j++)
        {
            a[j]=m;
        }

    }
    for(int i=1;i<=n/2;i++)
    {
        b[i]=a[i];
        c[i]=a[i];
    }
    for(int i=n/2;i>=1;i--)
    {
        if(c[i]!=b[n/2-i])
        {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}