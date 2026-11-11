#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
long long opt[500005];
long long n,m;
long long solve(long long e){
    memset(opt,0,sizeof(opt));
    long long cnt  = 1;
    long long rest = m;
    for(long long i = e; i >= 1;i--){
        if(cha[i]+opt[i] <= rest){
            opt[i-1] = cha[i]+opt[i];
            rest -= (cha[i]+opt[i]);
            cnt++;
        }else{
            return cnt;
        }
    }
    return cnt;
}
void A(){
    long long l = 1, r = n;
    long long mid = (l+r)/2;
    while(l+1 < r){
        mid = (l+r)/2;
        if(mid*(mid+1)/2 > m){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r;
}
void B(){
    long long l = 1, r = n, ca = a[2]-a[1];
    long long mid = (l+r)/2;
    while(l+1 < r){
        mid = (l+r)/2;
        if(mid*(mid+1)/2*ca > m){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout<<r;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int isA = 1, isB = 1;
    long long minn = 1e9, maxn = -1e9;
    for(long long i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] != i){
            isA = 0;
        }
        if(i >= 3&&a[i]-a[i-1] != a[i-1] - a[i-2]){
            isB = 0;
        }
        minn = min(minn,a[i]);
        maxn = max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    if(isA){
        A();
        return 0;
    }
    if(isB){
        B();
        return 0;
    }
    for(long long i = 1; i <= n; i++){
        cha[i] = a[i]-a[i-1];
        //cout<<cha[i]<<" ";
    }
    //cout<<endl;
    long long ans = -1e9, maxind;
    for(long long i = n; i >= 1; i--){
        if(solve(i) > ans){
            ans = solve(i);
            maxind = i;
        }
    }
    cout<<ans;
}
