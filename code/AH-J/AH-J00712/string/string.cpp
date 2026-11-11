#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,len,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;
        char ch;
        cin>>a>>ch;
        len+=a;
        while(a--) s+=ch;
    }
    ll l=0,r=n;
    while(l<=r){
        if(s[l]!=s[r]) cnt++;
        l++,r--;
    }
    cout<<cnt;
    return 0;
}
