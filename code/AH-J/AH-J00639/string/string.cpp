#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a;
ll hw(string x,string y)
{
    ll cnt=0;
    for(ll i=0;i<x.size();i++)
    {
        if(x[i]!=y[x.size()-i-1])cnt++;
    }
    return cnt;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        ll s;
        char c;
        cin>>s>>c;
        if(s*n<=1e8)for(ll j=1;j<=s;j++)a+=c;
        else
        {
            cout<<0;
            return 0;
        }
    }
    string b,c;
    ll l=a.size();
    if(l%2==1)
    {
        for(ll i=l/2;i<l;i++)b+=a[i];
        for(ll i=0;i<l/2;i++)c+=a[i];
        cout<<hw(c,b);
    }
    else
    {
        for(ll i=0;i<l/2;i++)c+=a[i];
        for(ll i=l/2;i<l;i++)b+=a[i];
        cout<<hw(c,b);
    }
    return 0;
}
