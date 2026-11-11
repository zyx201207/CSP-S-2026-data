#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans,ch[N];
int check(int x){
    if(x==1) return 1;
    int num=ch[x],sum=a[1];
    for(int i=x+1;i<=n;i++){
        num=min(num,ch[i]+sum-(i-x)*a[i]);
        sum+=a[i-x+1];
    }
    return num<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ch[1]=0;
    for(int i=2;i<=n;i++){
        ch[i]=ch[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%lld",ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}