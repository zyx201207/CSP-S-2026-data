#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n, m;
    
    scanf("%lld%lld", &n, &m);
    priority_queue<ll> a;
    for(int i = 0; i < n; ++i){
        ll ene;
        scanf("%lld", &ene);
        a.push(-ene);
    }
    
    ll sum = 0;
    ll mx = -1;
    for(ll i = 0; i < m; ++i){
        ll tp = -a.top();
        a.pop();
        tp++;
        a.push(-tp);
    }
    ll ans = -a.top();
    while(!a.empty()){
        ll cttp = -a.top();
        if(cttp == ans){
            sum++;
        }
        else{
            break;
        }
        a.pop();
    }
    
    printf("%lld", sum);
    /*
    while(!a.empty()){
        //cout << -a.top() << " ";
        a.pop();
    }
    */
    


    return 0;
}