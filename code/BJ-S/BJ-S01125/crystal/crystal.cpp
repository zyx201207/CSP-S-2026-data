#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long d[500005];
int n;
long long m;
bool check(int x){
    long long sum = 0;
    for(int i = x;i <= n;i++){
        sum = 0;
        for(int j = i - x + 1;j < i;j++){
            sum += a[i] - a[j];
        }
        if(sum <= m){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int f = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] != i){
            f = 1;
        }
    }
    sort(a + 1,a + n + 1);
    if(f == 0){
        long long ans = 0;
        for(long long i = 1;i <= sqrt(2 * m);i++){
            if(i * (i+1) <= 2 * m){
                ans = 1 + i;
            }
        }
        cout<<ans;
        return 0;
    }
    int h = 0;
    long long k = a[2] - a[1];
    for(int i = 1;i < n;i++){
        d[i] = a[i + 1] - a[i];
        if(d[i] != k){
            h = 1;
        }
    }
    if(h == 0){
        long long ans = 0;
        for(long long i = 1;i <= sqrt(2 * m / k) + 1;i++){
            if(i * (i+1) <= 2 * m * 1.00 / k){
                ans = 1 + i;
            }
        }
        cout<<ans;
        return 0;
    }
    int L = 1,R = n;
    int ans = 0;
    while(L <= R){
        int mid = L + (R-L) / 2;
        if(check(mid)){
            ans = mid;
            L = mid + 1;
        }else{
            R = mid - 1;
        }
    }
    cout<<ans;
    return 0;
}