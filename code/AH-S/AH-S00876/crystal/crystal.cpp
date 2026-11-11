#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long dp[500005];
long long diff[500005];
long long last = 0;
long long lastid = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 1;i<n;i++){
        diff[i] = a[i]-a[i-1];
    }
    long long maxn = 1;
    for(int i = 1;i<n;i++){
        last += (i-lastid)*diff[i];
        while(last > m){
            last = last-(a[i]-a[lastid]);
            lastid++;
        }
        maxn = max(maxn,i-lastid+1);
    }
    cout << maxn;
    return 0;
}
