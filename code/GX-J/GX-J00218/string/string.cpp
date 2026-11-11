#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("string.in","r",stdin);1
    freopen ("string.out","w",stdout);
    long long n,sum=0,x=0;
    char m;
    string a;
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
        cin>>x;
        cin>>m;
        for (long long j=1;j<=x;j++)
        {
            a+=m;
        }
    }
    for (long long i=0;i<a.size()/2;i++)
    {
        if (a[i]!=a[a.size()-i-1])
        {
            a[a.size()-i-1]=a[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

