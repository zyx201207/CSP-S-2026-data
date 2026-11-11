#include<bits/stdc++.h>
using namespace std;
long long n,m,now=1,cnt,ans=1,a[500010];
long long read(){
    long long x=0,p=1;char ac=getchar();
    while(ac!='-' && (ac<'0' || ac>'9')) ac=getchar();
    if(ac=='-') p=-1,ac=getchar();
    while(ac>='0' && ac<='9') x=x*10+ac-'0',ac=getchar();
    return x*p;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(long long i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
        cnt+=(a[i]-a[i-1])*(i-now);
        while(cnt>m) cnt-=(a[i]-a[now]),now++;
        ans=max(ans,i-now+1);
    }
    return !printf("%lld",ans);
}