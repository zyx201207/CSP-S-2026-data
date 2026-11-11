#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a;
char c;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(ll j=1;j<=a;j++)
        {
            s.push_back(c);
        }
    }
    ll len=s.size();
    s=" "+s;
    ll j=len;
    ll ans=0;
    for(ll i=1;i<=j;i++)
    {
        if(s[i]!=s[j])ans++;
        j--;
    }
    cout<<ans;
    return 0;
}
