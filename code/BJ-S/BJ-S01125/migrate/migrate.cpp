#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        long long d;
        cin>>n>>d;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        int f = 0;
        long long k = a[2]-a[1];
        for(int i = 2;i <= n;i++){
            if(a[i] - a[i-1] != k){
                f = 1;
            }
        }
        long long ans = 0;
        if(f == 0){
            if(d % k == 0 && d / k == 2){
                ans = n - 3;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}