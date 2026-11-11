#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500010],b[300010],c[300010],cnt;
string s[300010];
ll n,m;
ll minn=0x3f3f3f3f3f3f3f3f;
ll ans[300010];
string dfs(ll t)
{
    char k=a[t]+'0';
    ll p=a[t];
//    cout<<t<<"^"<<k<<"&"<<p<<'\n';
    if(s[p].size()!=0) return s[p];
    if(t==n)
    {
        s[p]=k;
        return s[p];
    }
    if(b[p]==t)
    {
        s[p]=k+dfs(t+1);
        return s[p];
    }
    else
    {
        if(s[p].size()==0) dfs(t+1);
        return dfs(b[p]);
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cout<<1111111;
    cin>>n>>m;
    //cout<<n<<m;
    for(ll i=1;i<=n;i++)
    {
      //  cout<<i<<'\n';
        cin>>a[i];
      //  cout<<")";
        b[a[i]]=i;
        c[a[i]]++;
       // cout<<i<<' '<<a[i]<<' '<<b[a[i]]<<' '<<c[a[i]]<<'\n';
    }
    for(ll i=1;i<=m;i++)
    {
        minn=min(minn,b[i]);
    }
    for(ll i=1;i<=m;i++)
    {
 //       cout<<"****"<<i<<' '<<c[i]<<'\n';
    }
//    cout<<minn<<'\n';
    string oo=dfs(minn);
    for(int i=1;i<=m;i++)
    {
//        cout<<i<<' '<<s[i]<<'*'<<'\n';
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=0;j<s[i].size();j++)
        {
            ll uu=s[i][j]-'0';
            ans[uu]+=c[i];
//            cout<<"&&"<<i<<' '<<j<<' '<<uu<<' '<<'\n';
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
//15 5
//5 1 3 4 1 2 5 4 4 3 2 1 1 2 5
