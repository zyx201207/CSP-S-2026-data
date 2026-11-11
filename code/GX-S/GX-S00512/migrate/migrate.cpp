#include<bits/stdc++.h>
using namespace std;
long long c , t;
int a[100001] , w , k , n , d , ans;
int main(){
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>c>>t;
    for(int j = 0 ; j < t ; j++){
        cin>>n>>d;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        w = a[1] - a[0];
        k = d/w;
        if(2*k-1<=n){
            ans+=n-2*k+1;
        }
        if(j!=t-1) cout<<ans<<"\n";
        else cout<<ans;
        ans=0;
    }
    return 0;
}
