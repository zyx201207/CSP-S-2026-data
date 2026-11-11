#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
ll n,m,a[N],ans=1,b[N],k,h[N],h2[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int j=0;j<n;j++){
        for(ll i=1;i<n-j;i++){
            b[i]=a[i+1]-a[i];
        }
        for(ll i=n-1-j;i>=1;i--){
            h[i]=h[i+1]+b[i];
        }
        for(ll i=n-1-j;i>=1;i--){
            h2[i]=h2[i+1]+h[i];
            if(h2[i]<=m){
                k=n-i+1-j;
            }else{
                break;
            }
        }
        if(k>=ans){
            ans=k;
        }

        for(ll i=1;i<n-j;i++){
            b[i]=0;
            h[i]=0;
            h2[i]=0;
        }
    }
    cout<<ans;


    return 0;
}