#include<bits/stdc++.h>
using namespace std;

long long l, r, a[501000], n, maxn = 1, m, anc[500100];

bool cmp(long long x, long long y){
    return x < y;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++){
        anc[i] = anc[i-1]+a[i];
    }
    for(long long l = 1, r = 2; r <= n && l <= r; r=r){
        long long now = anc[r]-anc[l-1], goal = a[r]*(r-l+1);
        long long re = goal-now;
        if(re <= m){
            maxn = max(maxn, (r-l+1));
            r++;
        }else{
            l++;
        }
    }
    cout<<maxn;
    return 0;
}
