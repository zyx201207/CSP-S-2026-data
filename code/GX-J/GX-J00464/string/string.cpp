#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
char a;
ll n,ans;
int main(){
    cin>>n;
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    for(ll i=0;i<n;++i){
        ll p;char b;
        cin>>p>>b;
        for(ll i=0;i<p;++i){
            s+=b;
        }
    }
    ll len=s.size(),l=0,r=len-1;
    while(l<r){
        if(s[l]!=s[r])l++,r--,ans++;
        else l++,r--;
    }
    cout<<ans;
    return 0;
}
