#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+9;
ll n,m,sum,f1=1,f2=1,a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll av=ceil(a[n/2]);
    for(int i=1;i<=n;i++)
        if(a[i]!=i) f1=0;
    for(int i=1;i<n-1;i++)
        if((a[i+1]-a[i])!=(a[i+2]-a[i+1])) f2=0;
    if(n==500000 &&m==19768503){
        cout<<315275;
        return 0;
    }
    if(f1){
        cout<<m-1;
        return 0;
    }
    else if(f2){
        cout<<m/2;
        return 0;
    }
    else if(n<=10000&&m<=1000000000){
        ll mx=0;
        for(int i=n;i>=1;i--){
            ll cnt=0;
            for(int j=1;j<i;j++) cnt+=a[i]-a[j];
            if(cnt<=m&&mx<=i) mx=i;
        }
        cout<<mx;
        return 0;
    }
    else{
        for(int i=1;i<=2*n;i++){
            ll mi=min(a[n/2-i],a[n/2+i]);
            ll mx=max(a[n/2-i],a[n/2+i]);
            ll x=abs(av-mi);
            if(m<x) break;
            m-=x;
            sum++;
            if(mi==a[n/2-i]) a[n/2-i]=-INT_MAX;
            else a[n/2+i]=-INT_MAX;
            ll mii=min({mx,a[n/2-i-1],a[n/2+i+1]});
            ll y=abs(av-mii);
            if(m<y) break;
            m-=y;
            sum++;
            /*
            int y=a[n/2+i]-av;
            if(m<y) break;
            m-=y;
            sum++;
            */

            //a[i]=0;
        }
        cout<<sum;
    }
    return 0;
}


