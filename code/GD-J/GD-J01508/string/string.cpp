#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ll n,ans=0;cin>>n;
    string s;
    for(ll i=0;i<n;i++) {
        int a;
        string b;
        cin>>a>>b;
        for(ll _=0;_<a;_++) s+=b;
    }
    for(ll i=1;i<=s.size()/2;i++) {
        if(s[i-1]!=s[s.size()-i]) ans++;
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
