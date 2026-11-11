#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll n,m,a[N],maxn=-1,id;
bool ok=1,xt=1;
map<ll,ll> mp;
ll gt(ll m)
{
    int i=lower_bound(a+1,a+n+1,id)-a-1,j=upper_bound(a+1,a+n+1,id)-a;
    ll sum=maxn;
    while(i!=-1 && m>=id-a[i])
    {
        m-=id-a[i--];
        sum++;
    }
    while(j!=n+1 && m>=(a[j]-id)*sum)
    {
        m-=(a[j]-id)*sum;
        sum+=mp[a[j]],j+=mp[a[j]];
    }
    return sum;
}
ll zt(ll m)
{
    ll sum=mp[a[1]];
    int i=1;
    while(m>=(a[i+1]-a[i])*sum)
    {
        m-=(a[i+1]-a[i])*sum;
        sum+=mp[a[i+1]],i+=mp[a[i+1]];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if(i<2)
            continue;
        if(i==2)
        {
            if(a[i]!=a[i-1])
                xt=0;
            continue;
        }
        if(a[i]-a[i-1]!=a[2]-a[1])
            ok=0;
    }
    if(n==1)
    {
        cout << 1;
        return 0;
    }
    for(auto i:mp)
    {
        if(i.second>maxn)
        {
            maxn=i.second;
            id=i.first;
        }
    }
    if(m==0 || xt)
    {
        cout << maxn;
        return 0;
    }
    if(ok)
    {
        ll k=a[2]-a[1],sum=1;
        while(m>=sum*k)
            m-=sum++;
        cout << sum-1;
    }
    else
    {
        sort(a+1,a+n+1);
        cout << gt(m) << " " << zt(m) << "\n";
        cout << max(gt(m),zt(m));
    }
    return 0;
}
