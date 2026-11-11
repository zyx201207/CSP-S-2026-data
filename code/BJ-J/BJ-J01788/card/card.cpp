#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
ll n,m,a[N],t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==2){
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            t[a[i]]++;
        }
        for(ll i=1;i<=2;i++){
            cout<<t[i];
        }
    }
    return 0;
}