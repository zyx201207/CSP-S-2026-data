#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    ll n,m,ans=0,l=0;
    char c;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>m>>c;
        while(m--){
            s+=c;
        }
    }
    l=s.size();
    for(ll i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
