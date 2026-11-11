#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,num;
stack <ll> s;
ll a[500005],abb[500005],abc[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>abc[i];
    }
    abc[0]=-50;
    for(ll i=1;i<=n;i++){
        if(abc[i]!=abc[i-1]){
            abb[abc[i]]+=i;
        }
        else{
            abb[abc[i]]+=1;
        }
    }
    for(ll i=1;i<=m;i++){
        cout<<abb[i]<<' ';
    }
    return 0;
}
