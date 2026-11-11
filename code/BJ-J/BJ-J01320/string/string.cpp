#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
struct Seg
{
    ll l,r;
    char c;
};
vector<Seg>l_s;
vector<Seg>r_s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    ll len=0;
    for(int i=1;i<=n;i++) len+=a[i];
    ll index=1;
    for(int i=1;i<=n;i++)
    {
        ll l=index;
        ll r=index+a[i]-1;
        index=r+1;
        l_s.push_back({l,r,c[i]});
        r_s.push_back({len-r+1,len-l+1,c[i]});
    }
    reverse(r_s.begin(),r_s.end());
    int it1=0,it2=0;
    ll id=1;
    ll ans=0;
    ll mid=(len)>>1;
    while(id<=mid)
    {
        // cerr<<id<<' '<<it1<<' '<<it2<<' '<<l_s[it1].r<<' '<<r_s[it2].r;
        char c1=l_s[it1].c;
        char c2=r_s[it2].c;
        ll nxt=min(l_s[it1].r,r_s[it2].r)+1;
        nxt=min(nxt,mid+1);
        if(c1!=c2)
        {
            ans+=nxt-id;
            // cerr<<"(+"<<ans<<")";
        }
        // cerr<<endl;
        id=nxt;
        if(nxt>l_s[it1].r) it1++;
        if(nxt>r_s[it2].r) it2++;
    }
    cout<<ans;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/