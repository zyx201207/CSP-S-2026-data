#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sn;
int t[27];
char s[100000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(ll i=1;i<=n;i++){
        ll a;
        char b;
        cin>>a>>b;
        t[b-96]=1;
        for(ll j=1;j<=a;j++){
            s[sn]=b;
            sn++;
            //cout<<i<<" ";
        }
    }
    int h=0;
    for(int i=0;i<=26;i++){
        if(t[i])h++;
    }
    if(h==1) {
        cout<<0;
        return 0;
    }
    ll ans=0;
    for(ll i=0;i<sn/2;i++){
        if(s[i]!=s[sn-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
