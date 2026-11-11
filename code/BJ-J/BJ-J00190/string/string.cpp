#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200010],b[200010];
ll cnt=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    //cout<<n<<"&&";
    for(ll i=1;i<=n;i++)
    {
        char s;
        cin>>a[i]>>s;
        b[i]=s-'a';
        //cout<<a[i]<<' '<<b[i]<<'*'<<'\n';
    }
/*    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' '<<b[i]<<'*'<<'\n';
    }*/
    for(ll i=1,j=n;i<=j;)
    {
        ll k=min(a[i],a[j]);
       // cout<<i<<' '<<j<<' '<<a[i]<<' '<<a[j]<<' '<<k<<'\n';
        if(b[i]!=b[j]) cnt+=k;
        if(a[i]==k)
        {
            i++;
        }
        else
        {
            a[i]-=k;
        }
        if(a[j]==k)
        {
            j--;
        }
        else
        {
            a[j]-=k;
        }
    }
    cout<<cnt;
    return 0;
}
