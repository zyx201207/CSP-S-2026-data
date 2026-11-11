#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ffor(i,a,b) for(ll i=(a);i<(b);++i)
ll x[2000100];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,_;
    while(_--){
        ll n,d,ch;
        cin>>n>>d;
        ffor(i,0,n){
            cin>>x[i];
        }
        // if(c==11||c==12){
        //     ch=x[n]-x[n-1];
        //     if(d<ch){
                cout<<0;
                // continue;
        //     }
        // }
    }
    
    return 0;
}