#include <bits/stdc++.h>
using namespace std;

long long n;
long long ans;
long long a[200000];
char c[200000];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(long long l=1,r=n;l<r;)
        if(a[l]<a[r])
        {
            if(c[l]!=c[r]) ans+=a[l];
            a[r]-=a[l]; l++;
        }
        else
        {
            if(c[l]!=c[r]) ans+=a[r];
            a[l]-=a[r]; r--;
        }
    cout<<ans;
    return 0;
}
