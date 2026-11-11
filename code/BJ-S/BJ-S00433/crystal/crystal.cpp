
#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,m,a[500010];
long long readll(){
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
long long check(int x){
    long long res=0,step=m;
    for(int j=x;j>0;j--){
        if(step>=a[x]-a[j]){
            res++;
            step-=(a[x]-a[j]);
        }else{
            break;
        }
    }
    return res;
}
void solve(){
    long long t=0,d=a[1]-a[0];
    if(d==0){
        printf("%d",n);
        return;
    }
    while(m){
        if(m>t*d){
            ans++;
            m-=t*d;
        }else break;
        t++;
    }
    ans=min(ans,(long long)n);
    printf("%lld",ans);
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        a[i]=readll();
    }
    sort(a+1,a+1+n);
    if(n>5000){
        solve();
        return 0;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,check(i));
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
