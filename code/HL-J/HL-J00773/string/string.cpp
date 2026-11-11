#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,sum=0,t=0,ans=0;
    cin>>n;
    vector<char> v;
    char last;
    while(n--)
    {
        ll a;
        char c;
        cin>>a>>c;
        t+=a;
        last=c;
        if(last==c) sum++;
        for(int i=1; i<=a; i++) v.push_back(c);
    }
    if(sum==n)
    {
        cout<<0;
        return 0;
    }
    ll i=0,j=t-1;
    while(i<t/2&&j>t/2)
    {
        if(v[i]!=v[j]) ans++;
        i++,j--;
    }
    cout<<ans;
    return 0;
}
