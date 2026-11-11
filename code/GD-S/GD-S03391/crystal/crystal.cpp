#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int n;
long long m;
long long a[510000];
bool check(int k) {
    // printf("hello\n");
    long long sum=0;
    for(int i=1;i<k;i++) sum+=a[k]-a[i];
    long long ans=sum;
    for(int j=k+1;j<=n;j++) {
        sum+=k*(a[j]-a[j-1]);
        sum+=a[j-k]-a[j];
        ans=min(ans,sum);
    }
    return ans<=m;
}
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    int l=1,r=n;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(check(mid)) {
            l=mid+1;
        }
        else {
            r=mid-1;
        }
    }
    printf("%d\n",r);
}