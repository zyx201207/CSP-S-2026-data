#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    int a[n+1];
    a[0]=0;
    char b[n+1];
    long long c[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
        c[i]=sum;
    }
    long long buget=0,ans=0;
    for(int i=1;i<=n/2;i++)
    {
        if(b[i]!=b[n-i+1])
        {
            ans+=min(a[i],a[n-i+1]);
        }
    }
    cout<<ans;
    return 0;
}
