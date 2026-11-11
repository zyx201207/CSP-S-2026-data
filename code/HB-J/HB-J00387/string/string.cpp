#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll a;
    cin>>a;
    string s;
    ll x,k=0;
    char y;
    for(ll i=0;i<a;i++){
        cin>>x>>y;
        for(ll j=0;j<x;j++)s+=y;
    }
    ll l=0,r=s.size()-1;
    while(r>l){
        if(s[l]!=s[r])k++;
        r--;l++;
    }
    cout<<k;
    return 0;
}
