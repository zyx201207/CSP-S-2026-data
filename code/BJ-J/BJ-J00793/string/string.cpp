#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
array<ll,200003>a;
array<char,200003>s;
int n;
ll L,m,ans,l,r;
ll hw(ll x)
{
    return L-1-x;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string st;
        cin>>a[i]>>st;
        s[i]=st[0];
        L+=a[i];
    }
    m=((L-1)>>1);
    l=0;r=L-1;int i=-1,j=n;
    while(l<=m||hw(r)<=m)
    {
        //cout<<i<<" "<<j<<" "<<l<<" "<<r<<" ";
        while(l<=hw(r)&&l<=m)
        {
            ll l2=l;
            l+=a[++i];
            if(l>hw(r))
            {
                if(s[i]!=s[j])
                {
                    ans+=hw(r)-l2;
                }
            }
            else
            {
                if(s[i]!=s[j])
                {
                    ans+=a[i];
                }
            }
        }
        //cout<<ans<<" ";
        while(hw(r)<l&&hw(r)<=m)
        {
            ll r2=r;
            r-=a[--j];
            if(hw(r)>=l)
            {
                if(s[i]!=s[j])
                {
                    ans+=l-hw(r2);
                }
            }
            else
            {
                if(s[i]!=s[j])
                {
                    ans+=a[j];
                }
            }
        }
        //cout<<ans<<endl;
    }
    cout<<ans;
    return 0;
}
