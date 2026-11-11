#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum=0;
string f(string n){
    string m="";
    for(ll i=n.size()-1;i>=0;i--){
        m+=n[i];
    }
    return m;
}
void g(string a,string b){
    for(ll i=0;i<a.size();i++){
        if(a[i]!=b[i]){
            sum++;
        }
    }
}
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ll n,a,h;
    char s;
    string x="",hx="",xs="";
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a>>s;
        for(int j=0;j<a;j++){
            x+=s;
        }
    }
    h=x.size()/2;
    for(ll i=0;i<h;i++){
        hx+=x[i];
    }
    hx=f(hx);
    for(ll i=0;i<x.size()-h;i++){
        xs+=x[i];
    }
    xs+=hx;
    g(x,xs);
    cout<<sum;
    return 0;
}
