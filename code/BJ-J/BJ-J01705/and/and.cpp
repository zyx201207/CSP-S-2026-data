#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[200010];
int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>s[i];
    }
    ll ma=-1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            ll a=s[m];
            int two[200010];
            ll i=1;
            ll sum=0;
            while(a!=0){
                two[i]=a%2;
                a%=2;
                i++;
            }
            int fang=i;
            for(int i=fang;i>=0;i--){
                sum+=pow(two[fang],fang);
            }
            int now=sum;
        }
    }
    return 0;
}
