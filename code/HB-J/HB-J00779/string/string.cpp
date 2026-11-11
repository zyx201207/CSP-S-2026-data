#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],l=1,t=0;
string b[1000005],w[1000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        l+=a[i];
    }
    if(l>=1e9)
    {
        cout<<l/2;
        return 0;
    }
    l=1;
    for(long long i=1;i<=n;i++)
    {
        for(long long j=l;j<l+a[i];j++) w[j]=b[i];
        l+=a[i];
    }
    l--;
    for(long long j=l,i=1;i<=l/2;i++)
    {
        if(w[i]!=w[j]) t++;
        j--;
    }
    cout<<t;
    return 0;
}
