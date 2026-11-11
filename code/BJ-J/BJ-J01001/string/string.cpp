#include<bits/stdc++.h>
using namespace std;
string s;
typedef long long ll;
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;string c;
        cin>>a>>c;
        for(ll j=1;j<=a;j++) s+=c;
    }
    for(ll frontt=0,endd=s.size()-1;frontt<endd;frontt++,endd--)
        if(s[frontt]!=s[endd]) ans++;
    cout<<ans<<endl;
    return 0;
}
