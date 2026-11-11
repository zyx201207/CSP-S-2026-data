#include<cstdio>
using namespace std;
#define N 2000006
int C,t,n;
/*
long long d;
long long x[N];
bool dp[5002][5002];
int need1[N],need2[N],left[N],right[N];
int main(){
    // freopen("migrate.in","r",stdin);
    // freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int c=0;c<n;c++) scanf("%lld",x+c),need1[c]=need2[c]=0;
        for(int c=0;c<n;c++){
            int i;
            need1[c]=need2[c]=1;
            for(i=c;i>=0;i--){
                if(x[c]-x[i]>d) break;
                dp[i][c]=1;
            }
            if(i+1!=c) need1[c]+=need1[i+1];
            left[c]=i+1;
            for(i=c+1;i<n;i++){
                if(x[i]-x[c]>d) break;
                dp[c][i]=1;
            }
            right[c]=i-1;
            if(i-1!=c) need2[c]+=need2[i-1];
        }
        for(int c=0;c<n;c++){
            for(int i=left[c];i>0;i=left[i]){
                dp[i][c]=1;
                if(i==left[i]) break;
            }
            for(int i=right[c];i<n;i=right[i]){
                dp[c][i]=1;
                if(i==right[i]) break;
            }
        }
        for(int c=1;c<n;c++){
            if(x[c]-x[c-1]<=d){
                for(int i=)
            }
        }
        long long ans=0;
        printf("%lld\n",ans);
    }
    return 0;
}
*/
// /*
int need1[N],need2[N];
long long d;
long long x[N];
long long dp1[N],dp2[N];
int find(long long f){//x[ans]>=f
    int l=0,r=n,m;
    while(l<r){
        m=(l+r)>>1;
        if(x[m]<f) l=m+1;
        else r=m;
    }
    return l;
}
int find2(long long f){//x[ans]>f
    int l=0,r=n,m;
    while(l<r){
        m=(l+r)>>1;
        if(x[m]<=f) l=m+1;
        else r=m;
    }
    return l;
}
long long ask1(int l,int r){
    long long ans=0;
    for(int c=l;c<r;c++) ans+=dp1[c];
    return ans;
}
long long ask2(int l,int r){
    long long ans=0;
    for(int c=l;c<r;c++) ans+=dp2[c];
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int c=0;c<n;c++) scanf("%lld",x+c),need1[c]=need2[c]=0;
        x[n]=3e8+5;
        for(int c=0;c<n;c++){
            int tmp=find(x[c]-d);
            if(tmp!=c) need2[tmp]++;
            tmp=find2(x[c]+d)-1;
            if(tmp!=c) need1[tmp]++;

        }
        for(int c=0;c<n;c++){
            int tmp=find(x[c]-d);
            dp1[c]=1+need1[c];
            // printf("1:%d %d\n",c,tmp);
            if(tmp!=c) dp1[c]+=ask1(find(x[tmp]-d),find(x[tmp+1]-d));
        }
        for(int c=n-1;c>=0;c--){
            int tmp=find2(x[c]+d)-1;
            dp2[c]=1+need2[c];
            if(tmp!=c) dp2[c]+=ask2(find2(x[tmp-1]+d),find2(x[tmp]+d));
        }
        // for(int c=0;c<n;c++) printf("%lld %lld\n",dp1[c],dp2[c]);
        long long ans=0;
        for(int c=2;c<n;c++){
            if(x[c]-x[c-1]<=d){
                for(int j=find(x[c]-d);j<c-1;j++){
                    if(find2(x[j]+d)-1!=c) break;
                    ans+=dp1[j]*ask2(find2(x[c-2]+d),find2(x[c-1]+d));
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
// */