#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,a;
    cin>>n;
    string s;
    string s1;
    ll cnt=0;
    while(n--){
        cin>>a>>s1;
        for(ll i=cnt;i<cnt+a;i++){
            s+=s1;
        }
        cnt+=a;
    }
    ll ans=0;
    for(int i=0;i<(cnt+1)/2;i++){
        if(s[i]!=s[cnt-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
