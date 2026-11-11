#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const long long Inf=1e18;
int n,m;
long long a[N];
long long sum[N];
bool Check(int x){
    for(int i=1;i+x-1<=n;i++){
        if(sum[i+x-1]-sum[i-1]>=x*a[i+x-1]-m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=0,r=5e5;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(Check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d",l);
    return 0;
}
