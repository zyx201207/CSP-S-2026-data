#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7;
ll c,t,n,m,a[N],ans,b[N],k;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        b[1]=a[2]-a[1];
        if(b[1]>m){
            cout<<0;
        }
        else{
            cout<<((n-b[1])/b[1])*(b[1]-1);
        }
    }
    return 0;
}