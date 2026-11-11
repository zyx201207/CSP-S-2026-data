#include <bits/stdc++.h>
using namespace std;
int a[100005];
int t[10000005];
int miju(int n){
    int min_ = 1000000;
    for(int i = 1;i <= n/2+1;i++){
        if(a[i+1]-a[i] < min_&&a[i+1]-a[i] != 0){
            min_ = a[i+1] - a[i];
        }
    }
    return min_;
}
int mihao(int n){
    int min_ = 1e18,mii;
    for(int i = 1;i <= n/2+1;i++){
        if(a[i+1]-a[i] < min_&&a[i+1]-a[i] != 0){
            min_ = a[i];
            mii = i;
        }
    }
    return mii;
}
int max_(int n){
    int maxx = -10000;
    for(int i = 1;i <= n;i++){
        if(a[i+1]-a[i] > maxx){
            maxx = a[i];
        }
    }
    return maxx;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt = 0,mmax = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    a[n+1] = 10000000;
    while(m >= miju(n)){
        int k = mihao(n);
        m -= miju(n);
        a[k] += a[k+1] - a[k];
        sort(a+1,a+n+1);
    }
    for(int i = 1;i <= max_(n);i++){
        t[a[i]]++;
    }
    for(int i = 1;i <= max_(n);i++){
        if(t[i] > mmax){
            mmax = t[i];
        }
    }
    cout<<mmax;
    return 0;
}
