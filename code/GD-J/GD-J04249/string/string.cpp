#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e+1;
int main(){
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    ll ans=0,n;
    cin>>n;
    ll a[N];
    string c[N];
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=(n+1)/2;i++){
        if(c[i]!=c[n-i+1]) ans+=min(a[i],a[n-i+1]);
    }
    cout<<ans;
}   
