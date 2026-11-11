#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,ans,mid;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
       cin>>a;
       cin>>c;
       for(ll j=1;j<=a;j++)s+=c;
    }
    mid=s.size()/2;
    for(ll i=0;i<mid;i++){
        if(s[i]!=s[s.size()-1-i]){s[s.size()-1-i]=s[i];ans++;}
    }
    cout<<ans;
    return 0;
}

