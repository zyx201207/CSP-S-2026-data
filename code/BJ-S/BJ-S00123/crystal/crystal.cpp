#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long sum[500005];
int ans=1;
bool check(int num,int id){
    long long rem=sum[id]-sum[num-1];
    if(1ll*(id-num+1)*a[id]-rem<=m)return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    sum[i]=sum[i-1]+a[i];
    for(int i=2;i<=n;i++){
        int l=0,r=i+1;
        while(l+1<r){
            int mid=(l+r)/2;
            if(check(mid,i))r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    printf("%d",ans);
    return 0;
}
