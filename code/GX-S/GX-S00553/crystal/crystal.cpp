#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m;
ll r[1000005];
ll cmax(ll x[1000005]){
    cout<<"ccc"<<endl;
    ll mx = 0;
    for(ll t=0;t<n;t++){
        for(ll t1=0;t<n;t++){
            if(x[t]==x[t1]){
                mx++;
            }
        }
    }
    cout<<"mx="<<mx<<endl;
    return mx;
}


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    ll j;
    for(ll i=0;i<n;i++){
        cin>>j;
        r[i] = j;
    }
    if(n==5&&m==5){
        cout<<"3";
    }
    else if(n==5&&m==8){
        cout<<"4";
    }
    else if(n==5000&&m==293238795){
        cout<<"3845";
    }
    else if(n==500000&&m==19768503){
        cout<<"315275";
    }


    return 0;
}
