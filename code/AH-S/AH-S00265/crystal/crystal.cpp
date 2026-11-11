#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long pre_sum=0;
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        pre_sum+=a[r];
        while((r-l+1)*a[r]-pre_sum>m){
            pre_sum-=a[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    printf("%d",ans);
    return 0;
}