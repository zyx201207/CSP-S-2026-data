#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n=0,z1,t=0,m=0;
    string s="",z;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>z1>>z;
        t+=z1;
        while(z1--){
            s+=z;
        }
    }
    for(ll i=0;i<t/2;i++){
        if(s[i]!=s[t-i-1]){
            m++;
        }
    }
    cout<<m;
    return 0;
}
