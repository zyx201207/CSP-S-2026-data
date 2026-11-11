#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,num;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>num>>c;
        for(ll j=1;j<=num;j++){
            s+=c;
        }
    }
    ll len=s.size();
    ll l=0,r=len-1,ans=0;
    while(l<=r){
        if(s[l]!=s[r])ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
