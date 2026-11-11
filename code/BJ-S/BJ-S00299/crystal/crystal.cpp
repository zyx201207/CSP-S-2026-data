#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],sum,mn,b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);

    }
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    int l=1,r=n+1,mid;
    while(l+1<r){
        mid=(l+r)/2;
        sum=(mid-1)*a[mid-1]-b[mid-2];
        mn=4000000000000000000ll;
        for(int i=mid;i<=n;i++){
            sum+=mid*(a[i]-a[i-1]);
            sum-=a[i]-a[i-mid];
            mn=min(mn,sum);
        }
        if(mn<=m){
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%d",l);
}
