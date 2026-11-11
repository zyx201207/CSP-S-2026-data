#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+5;
ll L1;
struct node{
    ll a;
    char c;
}a[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    ll n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].c;
        L1+=a[i].a;
        for(int j=1;j<=a[i].a;j++){
            s+=a[i].c;
        }
    }
    ll l=0,r=L1-1,ans=0;
    while(l<r){
        if(s[l]!=s[r]) ans++;
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}