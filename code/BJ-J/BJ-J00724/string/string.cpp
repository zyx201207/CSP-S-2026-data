#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s,p;
ll ans,n,t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>p;
        for (ll i=1;i<=n;i++){
            s+=p;
        }
    }
    for (ll i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

