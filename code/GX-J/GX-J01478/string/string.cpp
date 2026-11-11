#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char s[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
    for(int i=1;i<=n/2;i++) if(s[i]!=s[n-i+1]) ans+=min(a[i],a[n-i+1]);
    if(n%2!=0) ans+=a[n/2]-1;
    cout<<ans;
    return 0;
}
