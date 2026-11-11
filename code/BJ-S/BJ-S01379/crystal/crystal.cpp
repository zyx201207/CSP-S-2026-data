#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,c,s;
ll a[500050];
ll f(ll p){
    ll cnt = 0;
    ll i = 1;
    while(1){
        cnt += i;
        if(cnt > p){
            return i;
        }
        i++;
    }
}
int main(){
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    if(n == 1 || m==0){
        cout<<1;
        return 0;
    }
    sort(a + 1,a + n + 1);
    c = a[2]-a[1];
    s = m / c;
    if(s == 0){
        cout<<1;
        return 0;
    }
    cout<<f(s);

    return 0;
}
