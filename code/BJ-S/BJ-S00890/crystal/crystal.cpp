#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m,a[N];
bool check(int x){
    long long sum=0,res;
    for(int i=1;i<=x;++i) sum+=a[i];
    res=a[x]*x;
    if(res-sum<=m) return 1;
    for(int l=2;l<=n-x+1;++l){
        int r=l+x-1;
        sum-=a[l-1];
        sum+=a[r];
        res=a[r]*x;
        if(res-sum<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int l=1,r=n,ans;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}
