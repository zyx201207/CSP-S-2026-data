#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
string z2jz(ll s)
{
    string ans;
    while(s)
    {
        ans+=s%2+'0';
        s/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string yu(string x,string y)
{
    string ans;
    while(y.size()<x.size())y="0"+y;
    while(x.size()<y.size())x="0"+x;

    for(ll i=0;i<x.size();i++)
    {
        if(x[i]==y[i])ans+='1';
        else ans+='0';
    }
    string ann;
    ll o=1;
    for(ll i=0;i<ans.size();i++)
    {
        if(ans[i]=='0'&&o)continue;
        ann+=ans[i];
        o=0;
    }
    return ann;
}
bool cmp(ll x,ll y)
{
    return x>y;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    string ans=z2jz(a[1]);
    for(ll i=2;i<=m;i++)
    {
        ans=yu(z2jz(a[i]),ans);
    }
    ll sum=0,cu=1;
    for(ll i=ans.size()-1;i>=0;i--)
    {
        sum+=(ans[i]-'0')*cu;
        cu*=2;
    }
    cout<<sum;
    return 0;
}
