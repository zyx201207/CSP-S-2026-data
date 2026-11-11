#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    string a;
    for(ll i=1;i<=n;i++)
    {
        ll s;
        cin>>s;
        string q;
        cin>>q;
        while(s!=0)
        {
            a+=q;
            s--;
        }

    }
    string b,c;
    for(ll i=0;i<a.size() /2;i++)
    {
        b+=a[i];
    }
    for(ll i= a.size()-1;i>a.size() /2;i--)
    {
        c+=a[i];
    }
    ll sum=0;
    for(ll i=0;i<ceil(a.size()*1.0/2);i++)
    {
        if(b[i]!=c[i])
            sum++;
    }
    cout<<sum;
    return 0;
}
