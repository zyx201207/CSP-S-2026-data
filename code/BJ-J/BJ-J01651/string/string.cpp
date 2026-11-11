#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005
#define L 10000007
ll n,a[N],l;
char s[L],c[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(ll j=l+1;j<=l+a[i];j++)s[j]=c[i];
        l+=a[i];
    }
    ll ans=0;
    for(ll i=1;i<=l/2;i++)
    {
        if(s[i]!=s[l-i+1])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
