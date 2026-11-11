#include<bits/stdc++.h>
using namespace std;

int n,as;
long long m;
long long a[500010];
long long sum[500010];
int erfen(int k){
    int l=k,r=n,mid,re=k;
    while(l <= r){
        mid = (l+r)/2;
        if((a[mid]*(mid-k+1))-(sum[mid]-sum[k-1]) <= m){
            re = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return re;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        as = max(as,erfen(i)-i+1);
    }

    printf("%d",as);
    return 0;
}
