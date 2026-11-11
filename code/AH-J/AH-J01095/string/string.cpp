#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ffor(i,a,b) for(ll (i)=(a);(i)<(b);++(i))
ll diff(string a){
    ll res=0;
    ffor(i,0,a.size()/2+1){
        res+=(a[i]!=a[a.size()-1-i]);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    string s;
    ffor(i,0,n){
        ll a;char c;
        cin>>a>>c;
        ffor(i,0,a)s+=c;
    }
    cout<<diff(s);
    return 0;
}