#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005],x[200005]={0},m=1,k=0,p=0;
    char b[200005],y[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    x[1]=a[1];
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=b[i+1] and i+1<=n)
        {
            k++;
            break;
        }
    }
    if(k==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==b[i+1])
        {
            x[m]+=a[i+1];
            y[m]=b[i];
        }
        else
        {
            m++;
            x[m]=a[i+1];
        }
    }
    cout<<max(x[1],x[m-1]);
    return 0;
}
