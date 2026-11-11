#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
void ksj(string &s,ll a,char x){
    string k;
    k+=x;
    while(a){
        if(a&1)s+=k;
        k+=k;
        a>>=1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    while(n--){
        ll num;
        char a;
        cin>>num>>a;
        ksj(s,num,a);
    }
    ll ans=0;
    for(ll i=0;(i<<1)+1<=s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}