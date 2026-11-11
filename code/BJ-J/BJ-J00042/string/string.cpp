#include<bits/stdc++.h>
#define ll long long
#define int unsigned long long
const int maxn=2e5+5;
int n,a[maxn],gdv=1;
char c[maxn];
int ans=0;
using namespace std;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]>>c[i];
    gdv=a[0];
    for(int i=0;i<n;i++)gdv=__gcd(gdv,a[i]);
    for(int i=0;i<n;i++)a[i]/=gdv;
    int i=0,j=0;
    while(i<n)
    {
        s+=c[i];
        j++;
        if(j>=a[i])i++,j=0;
    }
    for(unsigned long long k=0;k<s.size()/2;k++)
    {
        if(s[k]!=s[n+k-1])ans++;
    }
    cout<<ans*gdv;
    return 0;
}
