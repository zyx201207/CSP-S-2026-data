#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll a[N],b[N],sum[N];
ll n,m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        //if(a[i]==a[i-1]) sum[i]=sum[i-1];
        //else sum[i]=sum[i-1]+a[i]-a[1];
    }
    //for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
    sort(a+1,a+n+1);
    /*for(int i=1;i<=n;i++)
    {
        ll x=1;
        while(sum[i]-sum[i-x]<=m&&i-x>=1)
        {
            x++;
        }
        //cout<<x<<' ';
        if(x>ans) ans=x;
    }*/
    for(int i=1;i<=n;i++)
    {
        ll x=1;
        ll cnt=0;
        while(cnt<=m&&i-x>=1)
        {
            cnt+=a[i]-a[i-x];
            if(cnt>m)
            {
                break;
            }
            else x++;
        }
        if(x>ans) ans=x;
    }
    /*ll pre=0,prev=0;
    for(int i=1;i<=n;i++)
    {
        ll cur=prev;
        ll num=cur+pre*b[i];
        if(num<=m)
        {
            prev=num;
            pre++;
            //cerr<<pre<<' ';
        }
        else
        {
            ll x=1;
            ll cnt=0;
            while(cnt<=m&&i-x>=1)
            {
                cnt+=a[i]-a[i-x];
                //prev=cnt;
                if(cnt>m)
                {
                    prev=cnt-a[i]+a[i-x];
                    break;
                }
                else x++;
            }
            pre=x;
            
            //cerr<<x<<' '<<prev;
        }
        if(pre>ans) ans=pre;
    }*/
    /*for(int i=1;i<=n;i++)
    {
        ll cur=0,x=1;
        
        ans=max(ans,x);
    }*/
    /*for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ll x=a[i];
        ll cur=0,num=0;
        for(int j=i;j>=1;j--)
        {
            cur+=x-a[j];
            if(cur>m) break;
            else num++;
        }
        if(num>ans) ans=num;
    }*/
    cout<<ans;
    return 0;
}