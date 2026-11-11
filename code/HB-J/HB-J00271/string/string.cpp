#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,char>
//dao na ge shi char c;
ll n;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(ll i=0;i<n;i++)
    {
        ll a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++)s=s+c;
    }
    ll ans=0;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
            ans++;
    }
    cout<<ans;
    return 0;
}
