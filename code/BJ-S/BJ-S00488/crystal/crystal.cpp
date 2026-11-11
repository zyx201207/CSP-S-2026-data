#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("r","crystal.in",stdin);
    freopen("w","crystal.out",stdout);
    cin>>n>>m;
    for(long long i = 0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans = 0;
    for(int i = 0;i<n;i++){
        long long sum = 0,t = 1;
        for(int j = i-1;j>=0;j--){
            if(sum+(a[i]-a[j])<=m){
                t++;
                sum+=(a[i]-a[j]);
            }
        }
        ans = max(ans,t);
    }
    cout<<ans;
    return 0;
}
