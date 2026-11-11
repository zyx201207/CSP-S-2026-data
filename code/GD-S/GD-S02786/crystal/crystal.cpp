#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,cha,ans=0;
vector<ll>c(500005),v(500005);
int main(){
    freopen("crytal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool TA=1,TB=1;
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        if(i!=1){
            if(c[i-1]!=c[i])TA=0;
            
        }
    }if(TA)cout<<n;
    else{
        sort(c.begin()+1,c.begin()+n+1);
        for(ll i=1;i<n;i++){
            v[i]=c[i+1]-c[i];
            if(i!=1&&v[i]!=v[i-1])TB=0;
        }
        if(TB){
            for(ll i=n-1;i>=1;i--){
                if(m>=v[1]){
                    ans++;
                    m-=v[1]*(n-i);
                }
            }
        }
        // else{

        // }
        cout<<ans;
    }return 0;
}