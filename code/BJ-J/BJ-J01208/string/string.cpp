
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a[200010];
char c[200010];
string s;
ll q;
ll ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(ll j=1;j<=a[i];j++)
        {
            s+=c[i];
        }
    }
    ll len=s.length();
    for(ll i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-1-i])ans++;
    }
    cout<<ans;
    return 0;
}
