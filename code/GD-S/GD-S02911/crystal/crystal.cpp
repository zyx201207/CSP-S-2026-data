#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long ans = 0,n,m,a[500010]={},b[500010]={};
    cin >> n >> m;
    for(long long i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(long long i = 1 ; i <= n ; i++){
            long long sum = 0;
            for(long long j = 1 ; j <= i ; j++){
                for(long long k = j ; k <= i ; k++){
                    sum += a[i] - a[k];
                }
                if(sum <= m) ans = max(ans,i-j+1);
            }
    }
    cout << ans;
    return 0;
}
