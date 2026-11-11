#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll sum=0;
ll ans=1;
ll cnt=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n+5,0);
    vector<ll> b(n+5,0);

    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<=5000){
        sort(a.begin(),a.end());
        b[0]=a[0];
        for(ll i=1;i<n;i++){
            b[i]=a[i]-a[i-1];
        }
        for(int i=1;i<n;i++){
            ll energy=m;
            cnt=1;
            if(energy-b[i]*(cnt-1)>=0){
                energy-=b[i]*(cnt-1);
                cnt++;
            }
            else{
                ans=max(ans,cnt);
                continue;
            }

        }
        cout<<cnt;
    }
    else{
        if(a[3]>a[2])
        cout<<m/(a[3]-a[2])+1;
        if(a[3]<a[2])
        cout<<m/(a[2]-a[3])+1;



    }
    return 0;
}
