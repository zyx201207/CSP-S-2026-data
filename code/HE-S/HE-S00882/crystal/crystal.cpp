#include <bits/stdc++.h>
using namespace std;

const int MAX_N=5e5;
using ll=long long;

int n;
ll m;
ll a[MAX_N+10];

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+n+1);
    int ans=0, pos=1;
    ll sum=0;
    for(int i=1; i<=n; i++){
        sum+=1ll*(a[i]-a[i-1])*(i-pos);
        while(pos<i && sum>m){
            sum-=a[i]-a[pos];
            pos++;
        }
        ans=max(ans, i-pos+1);
    }
    printf("%d\n", ans);

    return 0;

}
