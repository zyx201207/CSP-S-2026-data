#include <bits/stdc++.h>
using namespace std;
const long long maxn=1e5*2;
long long n,a[maxn],l,ans,h=0;
char c[maxn],s[maxn];
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
		cin>>a[i]>>c[i],l+=a[i];
        for (long long j=1;j<=a[i];j++)
        {
		   h++;
           s[h]=c[i];
        }
    }
    for (long long i=1;i<=l;i++)
    {
        if (s[i] != s[l-i+1]) s[l+1-i]=s[i],ans++;
    }
    cout<<ans;
    return 0;
}
