#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long sum[N];
long long m;
bool check(int i,int j){
    return ((i-1-j+1)*a[i]-(sum[i-1]-sum[j-1])) <= m;
}
int work(int x){
    int l=1,r=x-1;
    while(l<r){
        int mid=(l+r)/2;
        if (check(x,mid)) r=mid;
        else l=mid+1;
    }
    return x-l+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%lld",&m);
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for (int i=1;i<=n;i++){
        ans=max(ans,work(i));
    }
    printf("%d\n",ans);
    return 0;
}
