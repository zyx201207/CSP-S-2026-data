#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        ll h;
        for(int i=2;i<=n;i++){
            h=a[i-1]&a[i];
        }
        cout<<h;
    }else if(m==1){
        ll mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }else if(m==2){
        ll mx=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    mx=max(a[i]&a[j],mx);
                }
            }
        }
        cout<<mx;
    }
    return 0;
}
