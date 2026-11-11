#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll a;
string b;
string s;
set<string>st;
ll check(string s){
    ll ans=0;
    int n=s.size()/2;
    string y,x;
    if(s.size()+1%2==0){
        x=s.substr(0,n);
        for(int i=s.size()-1;i>n;i--) y+=s[i];
        for(int i=0;i<n;i++){
            if(y[i]!=x[i]) ans++;
        }
    }
    else{
        x=s.substr(0,n-1);
        for(int i=s.size()-1;i>n;i--) y+=s[i];
        for(int i=0;i<n-1;i++){
            if(y[i]!=x[i]) ans++;
        }
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        for(ll i=0;i<a;i++) s+=b;
        st.insert(b);
    }
    if(st.size()%2==1) cout<<check(s)+1;
    else cout<<check(s);
    return 0;
}
