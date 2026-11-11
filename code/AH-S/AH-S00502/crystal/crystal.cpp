#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n,c=0;
int a[500100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++){
        ll cnt=0,b=a[i];
        for(ll j=0;j<=i;j++){
            if(cnt>m){
                c=i;
                break;
            }
            cnt+=b-a[j];
        }
        if(c!=0)break;
    }
    cout<<c;
    return 0;
}
