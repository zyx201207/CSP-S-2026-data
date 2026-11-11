#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000010],mx;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }else if(m==n){
        ll sum=a[1];
        for(ll i=2;i<=n;i++){
            sum=sum&a[i];
        }
        cout<<sum;
        return 0;
    }else if(m==2){
        ll maxn=0;
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);

            }
        }
        cout<<maxn;
        return 0;
    }
    return 0;
}
