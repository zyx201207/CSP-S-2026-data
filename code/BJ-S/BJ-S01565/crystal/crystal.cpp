#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans[500005];
ll a[500005],c[500005],sum[500005],m,cnt;
int flagB;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        c[i]=a[i]-a[i-1];
        if(c[i]!=c[i-1]&&i!=2)flagB=1;
        sum[i]=sum[i-1]+c[i];
    }
    if(!flagB){
        for(int j=n;j>=1;j--){
            cnt+=sum[n]-sum[j];
            if(cnt<=m)ans[n]++;
            else break;
        }
        printf("%d",ans[n]);
        return 0;
    }
    if(n>5000){
        int b[210]={};
        for(int i=1;i<=n;i++)b[a[i]+100]++;
        for(int i=0;i<=210;i++){
            cnt=0;
            for(int j=i;j>=0;j--){
                if(cnt+b[j]*(i-j)<=m)cnt+=b[j]*(i-j),ans[i]+=b[j];
                else{
                    ans[i]+=(m-cnt)/(i-j);
                    break;
                }
            }
        }
        int nmax=0;
        for(int i=1;i<=n;i++)nmax=max(nmax,ans[i]);
        printf("%d",nmax);
        return 0;
    }

    for(int i=2;i<=n;i++){
        cnt=0;
        for(int j=i;j>=1;j--){
            cnt+=sum[i]-sum[j];
            if(cnt<=m)ans[i]++;
            else break;
        }
    }
    int nmax=0;
    for(int i=1;i<=n;i++)nmax=max(nmax,ans[i]);
    printf("%d",nmax);
    return 0;
}
