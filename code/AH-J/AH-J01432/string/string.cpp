#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll s[N];
char t[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,mn=0;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>s[i]>>t[i];
    ll s1=0,s2=0,ans=0,l=0,r=n+1;
    char t1,t2;
    while(l<r)
    {
        if(s1==0)
        {
            s1=s[++l];
            t1=t[l];
        }
        if(s2==0)
        {
            s2=s[--r];
            t2=t[r];
        }
        if(l>r)break;
        ll mn=min(s1,s2);
        if(t1!=t2)ans+=mn;
        s1-=mn,s2-=mn;
    }
    cout<<ans;
    return 0;
}
