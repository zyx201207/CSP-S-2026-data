#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e8+5;
ll a;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        ll p;
        char k;
        cin>>p>>k;
        for(int j=0;j<p;j++){
            s+=k;
        }
    }
    ll l=0,r=s.size()-1;
    ll sum=0;
    while(l<=r){
        if(s[l]!=s[r]){
            //cout<<l<<' '<<r<<endl;
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum<<endl;
    return 0;
}