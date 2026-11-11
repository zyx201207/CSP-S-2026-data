#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ll n=0,m=0;
    ll a[n]={0};
    ll wz[n][m]={0};
    ll cd[m]={0};
    ll izw[m]={0};
    ll qw[m][n]={0};
    for(ll i=0;i<n;i++){
        cin>>a[i];
        wz[cd[a[i]-1]][a[i]-1]=i;
        cd[a[i]-1]++;
    }
    qw[n-1][a[n]-1]++;
    for(ll i=n-2;i>=0;i--){
        for(ll o=0;o<m;o++){
            qw[i][o]=qw[i+1][o];
        }
        qw[a[i]-1][i]++;
    }
    ll cnt[m]={0};
    ll w=0;
    for(ll i=0;i<n;i++){
       w=i;

    }
    for(ll i=0;i<m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
