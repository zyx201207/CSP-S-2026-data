#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans=0;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=0;i<n;i++){
        ll a;
        char c;
        cin>>a>>c;
        for(ll j=0;j<a;j++){
            s=s+c;
        }
    }
    int l=s.size();
    int z=0,y=l-1;
    while(z<y){
        if(s[z]!=s[y]){
            ans++;
        }
        z++;
        y--;
    }
    cout<<ans;
    return 0;
}
