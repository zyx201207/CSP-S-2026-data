#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
struct str{
    ll a;
    char c;
}s[200005];
char g(ll n){
    for(ll i=0;i<t;i++){
        if(n<=s[i].a)return s[i].c;
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    ll cnt = 0;
    for(int i=0;i<t;i++){
        ll in;
        cin>>in>>s[i].c;
        cnt+=in;
        s[i].a=cnt;
    }
    ll ans = 0;
    for(ll i=1;i<=(cnt>>1);i++){
//cout<<i<<' '<<g(i)<<' '<<g(cnt+1-i)<<endl;
        ans+=(g(i)==g(cnt+1-i))?0:1;
    }
    cout<<ans;
    return 0;
}
