#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define dd double
#define ull unsigned long long
#define pq priority_queue
#define vec vector
using namespace std;
const string PUO="crystal";
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef cspjudge
    string filename_in=PUO+".in";
    string filename_out=PUO+".out";
    freopen(filename_in.c_str(),"r",stdin);
    freopen(filename_out.c_str(),"w",stdout);
    #endif
    ll n,m;
    cin>>n>>m;
    ll num[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>num[i];

    }
    sort(num+1,num+n+1);
    ll ans=0;
    for(ll i=n;i>ans;i--)
    {
        ll cnt=0;
        for(ll j=i;j>0;j--)
        {
            cnt=cnt+num[i]-num[j];
            if(cnt>m)
            {
                ans=max(ans,i-j);
                break;
            }
            else if(cnt==m)
            {
                ans=max(ans,i-j+1);
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}


//我去有中文lol
