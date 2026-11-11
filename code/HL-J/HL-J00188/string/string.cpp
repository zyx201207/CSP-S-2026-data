#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
ll cnt=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++){
            s+=c;
        }
    }ll k=s.size();
    if(k%2==1){
        k=(k+1)/2;
    }else
    {
        k/=2;
    }
    for(int i=1,j=k;i<=k&&j>=1;i++,j--){
            if(s[i]!=s[j]){
                cnt++;
            }
    }cout<<cnt;
    return 0;
}
