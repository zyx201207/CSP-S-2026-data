#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100000000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        ll t;
        char c;
        cin>>t>>c;
        for(ll i=1;i<=t;i++)
            cnt++,s[cnt]=c;
    }
    ll flag=0;
    for(ll i=1;i<=cnt/2;i++)
        if(s[i]!=s[cnt-i+1])
            flag++;
    cout<<flag;
    return 0;
}
