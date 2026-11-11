#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    cin>>a>>b;
    for(ll i=0;i<a;i++){
        cin>>s[i];
    }
    ll ma=0;
    for(ll i=0;i<a;i++){
        if(ma<s[i]){
            ma=s[i];
        }
    }
    cout<<ma;
    return 0;
}
