#include<bits/stdc++.h>
using namespace std;
long long  n  , maxn = INT_MIN , a[500010] , b[500010];
long long m , cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n; i++){
        b[i] = b[i-1]+a[i];
    }
    for(long long i = n;i >= 1; i--){
        for(long long j = i;j >= 1;j--){
            if((b[i]-b[j]+m) <= (i-j+1)*a[i]){
                maxn = max(maxn,i-j+1);
            }else{
                break;
            }
        }
    }
    cout << maxn;
    return 0;
}
