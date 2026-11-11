#include <bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define per(i,a,b) for (int i=a;i>=b;i--)
#define ll long long
using namespace std;
const int N=2*1e5+5;
ll n,ans;
string s;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s+=' ';
    rep(i,1,n){
        ll a;
        char c;
        cin>>a>>c;
        rep(i,1,a)s=s+c;
    }
    ll l=s.size()-1;
    //rep(i,1,l) {
    for(int i=1;i<l;i++){
        if(s[i]!=s[l+1-i]) {
            s[l+1-i]=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
