#include <bits/stdc++.h>
using namespace std;
string c,s,b1,b2;
long long n,a[200000005],ans=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=1;j<=a[i];j++) s+=c[i];
    }
    int l=s.size();
    for(long long i=0;i<l/2;i++) b1+=s[i];
    for(long long i=l-1;i>=l/2;i--) b2+=s[i];
    for(long long i=0;i<l/2;i++)
    {
        if(b1[i]!=b2[i]) ans++;
    }
    if(ans==0)
    {
        cout<<0;
        return 0;
    }
    else
    {
        cout<<ans;
        return 0;
    }
    return 0;
}
