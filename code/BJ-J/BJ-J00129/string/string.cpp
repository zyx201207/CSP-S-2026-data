#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long ans;
char look(long long i)
{
    long long pos=lower_bound(a+1,a+n+1,i)-a;
    return c[pos];
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;++i)
    {
        cin>>a[i]>>c[i];
        a[i]+=a[i-1];
    }
    for(long long i=1;i<=a[n]/2;++i)
    {
        if(look(i)!=look(a[n]-i+1))
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
