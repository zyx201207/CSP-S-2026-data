#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long int a[500005],d[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long int n, m;
    scanf("%lld%lld",&n,&m);
    bool flag=1;
    long long int gc;
    for(int i=1; i<=n; ++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1; i<=n; ++i){
        d[i-1]=a[i]-a[i-1];
        if(i>=2){
            gc=a[2]-a[1];
            if(d[i-1]!=gc)
                flag=0;
        }
    }
    if(flag){
        long long int cnt=0;
        int ans=1;
        for(int i=1; i<=n; ++i){
            cnt+=1LL*i*gc;
            if(cnt>m)
                break;
            ++ans;
        }
        printf("%d",ans);
        return 0;
    }

    long long int ans=0;
    for(int i=1; i<=n; ++i){
        long long int op=0,cnt=1;
        for(int j=i; j<=n; ++j){
            op+=1LL*(j-i+1)*d[j];
            if(op>m)
                break;
            ++cnt;
        }
        //printf("%d %d\n",cnt,op);
        ans=max(ans,cnt);
    }
    printf("%lld",ans);
    return 0;

}
