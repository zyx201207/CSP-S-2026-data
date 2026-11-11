#include <bits/stdc++.h>
using namespace std;
long long a[10005];
char c[10005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0;
    long long sum=0;
    long long flag=1;
    cin>>n;
    long long pos=n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    while(flag!=pos)
    {
        if(c[flag]!=c[pos]&&a[flag]<=a[pos])
        {
            sum+=a[flag];
            a[pos]-=a[flag];
            flag++;
        }
        else if(c[flag]!=c[pos]&&a[flag]>a[pos])
        {
            sum+=a[pos];
            a[flag]-=a[pos];
            pos--;
        }
        else if(c[flag]==c[pos]&&a[flag]>a[pos])
        {
            a[flag]-=a[pos];
            pos--;
        }
        else if(c[flag]==c[pos]&&a[flag]<=a[pos])
        {
            a[pos]-=a[flag];
            flag++;
        }
    }
    cout<<sum;
    return 0;
}