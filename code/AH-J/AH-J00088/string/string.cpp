#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string t;
ll n,s,k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll a;
        char c;
        cin>>a>>c;
        s+=a;
        while(a--){
            t+=c;
        }
    }
    for(ll l=0,r=s-1;l<r;l++,r--){
        if(t[l]!=t[r]) k++;
    }
    cout<<k;
    return 0;
}
