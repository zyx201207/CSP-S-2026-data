#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
long long b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n/2;i++)
    {
        if(c[i]-'a'!=c[n+1-i]-'a')
        {
            if(a[i]==a[n+1-i])
            {
                b+=a[i];
                c[i]=c[n+1-i];
            }
            if(a[i]<a[n+1-i])
            {
                a[i+1]=a[i+1]-a[n+1-i]+a[i];
                b+=a[n+1-i];
                a[i]=a[n+1-i];
                c[i]=c[n+1-i];
            }
            if(a[i]>a[n+1-i])
            {
                a[i+1]=a[i+1]+a[i]-a[n+1-i];
                b+=a[i];
                a[i]=a[n+1-i];
                c[i]=c[n+1-i];
            }
        }
        else
        {
            if(a[i]<a[n+1-i])
            {
                a[i+1]=a[i+1]-a[n+1-i]+a[i];
                b+=a[n+1-i]-a[i];
                a[i]=a[n+1-i];
            }
            if(a[i]>a[n+1-i])
            {
                a[i+1]=a[i+1]+a[i]-a[n+1-i];
                b+=a[i]-a[n+1-i];
                a[i]=a[n+1-i];
            }
        }
    }
    cout<<b;
    return 0;
}
