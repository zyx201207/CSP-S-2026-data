#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000010],b[1000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(a[1],a[2]);
        return 0;
    }
    return 0;
}
