#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(ll)(b);++i)
const int maxs=3000000;
const int inf=2e9+5000;
string s;
ll n;
ll g=0;
ll f[maxs][maxs];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
struct ques
{
    ll a;
    char c;
}q[200005];
int main(){
#if 1
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    rep(i,1,n)
    {
        cin>>q[i].a>>q[i].c;
        g=gcd(q[i].a,g);
    }
    if(g!=1)
        rep(i,1,n)
            s=s+string(q[i].a/g,q[i].c);
    int sz=s.size();
    s=' '+s;
    rep(len,1,sz)
    {
        rep(l,1,sz+1-len)
        {
            int r=l+len-1;
            ll res=f[l+1][r-1];
            if(s[l]!=s[r]) res++;
            f[l][r]=res;
        }
    }
    cout<<f[1][sz]*g;
    return 0;
}
