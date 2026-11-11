#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    ll n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        ll x;
        char c;
        cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
