#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,ans=0;
ll L,lmid,rmid;
ll a[200005];
char c[200005];
vector<pair<ll,char>> t1,t2;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n;
    for(ll i=1;i<=n;i++)cin>>a[i]>>c[i],L+=a[i],a[i]+=a[i-1];
    lmid=L>>1,rmid=lmid+1+(L&1);
    t1.push_back({0,'#'}),t2.push_back({0,'#'});
    for(ll i=n;i>=1;i--)
    {
        if(a[i-1]<lmid)
        {
            t1.push_back({lmid-a[i-1],c[i]});
            // cout<<lmid-a[i-1]<<' '<<c[i]<<'\n';
        }
    }
    // cout<<'\n';
    for(ll i=1;i<=n;i++)
    {
        if(a[i]>=rmid)
        {
            t2.push_back({a[i]-rmid+1,c[i]});
            // cout<<a[i]-rmid+1<<' '<<c[i]<<'\n';
        }
    }
    // cout<<'\n';
    ll x=0,y=0,p=0;
    while(1)
    {
        if((x==t1.size()-1)&&(y==t2.size()-1))break;
        if((x==t1.size()-1)){ans+=(t1[x+1].second!=t2[y+1].second)*(t2[y+1].first-p);y++;p=t2[y].first;}
        else if((y==t2.size()-1)){ans+=(t1[x+1].second!=t2[y+1].second)*(t1[x+1].first-p);x++;p=t1[x].first;}
        else if(t1[x+1].first>=t2[y+1].first){ans+=(t1[x+1].second!=t2[y+1].second)*(t2[y+1].first-p);y++;p=t2[y].first;}
        else {ans+=(t1[x+1].second!=t2[y+1].second)*(t1[x+1].first-p);x++;p=t1[x].first;}
    }
    cout<<ans;

    return 0;
}