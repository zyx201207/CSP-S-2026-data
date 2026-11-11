#include<cstdio>
#include<algorithm>
using namespace std;
#define N 500005
int n;
long long m,a[N];
bool check(int x){
    long long sum=0;
    for(int c=0;c<x;c++) sum+=a[c];
    if(a[x-1]*x-sum<=m) return 1;
    for(int c=x;c<n;c++){
        sum-=a[c-x];
        sum+=a[c];
        if(a[c]*x-sum<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int c=0;c<n;c++) scanf("%lld",a+c);
    sort(a,a+n);
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%d",l);
}