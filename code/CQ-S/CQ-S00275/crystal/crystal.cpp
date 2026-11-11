#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
int n;
ll m,a[MAXN],sum[MAXN];
bool check(int cnt){
    for(int i=cnt;i<=n;i++)
        if(cnt*a[i]-sum[i]+sum[i-cnt]<=m) return true;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
    #endif
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n,res=l;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            res=mid;
            l=mid+1;
        }else r=mid-1;
    }
    printf("%d",res);
    return 0;
}
/*
好像做过原题？二分答案，用前缀和来算，好像可以。
*/