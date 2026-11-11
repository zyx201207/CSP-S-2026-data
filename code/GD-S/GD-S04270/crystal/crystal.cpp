#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,j;
ll m,a[N],s[N],t,b[N],c[N],l,mx,now;
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    a[0]=-1e18;
    l=m;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])
        {
            s[t]++;
            c[t]=s[t];
            continue;
        }
        s[++t]++;
        c[t]=s[t];
        b[t]=a[i];
    }
    for(int i=1;i<=t;i++)
    {
        if(j>t)
        {
            break;
        }
        if(i!=1)
        {
            l+=(b[i-1]-b[i])*now;
            now-=min(now,s[i]);
        }
        j=max(i+1,j);
        while(j<=t)
        {
            ll k=b[i]-b[j];
            if(l<k)
            {
                break;
            }
            ll sum=min(c[j],l/k);
            l-=sum*k;
            now+=sum;
            c[j]-=sum;
            if(c[j])
            {
                break;
            }
            j++;
        }
        mx=max(mx,s[i]+now);
    }
    cout<<mx;
    return 0;
}
