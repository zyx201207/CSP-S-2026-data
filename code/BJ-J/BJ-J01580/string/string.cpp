#include <bits/stdc++.h>
using namespace std;
long long n,ans,b=1,l=1;
long long a[100000005],d[100000005];
char c[20005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j = l;j<=l+a[i];j++)
        {
            d[j] = c[i];
        }
        l+=a[i];
    }
    for(int i = l;i>=l/2;i--)
    {
        if(d[b]!=d[i])
        {
            ans++;
        }
        b++;
    }
    if(ans>=l/2)
        cout<<l/2;
    if(ans<l/2)
        cout<<ans;
    return 0;
}
