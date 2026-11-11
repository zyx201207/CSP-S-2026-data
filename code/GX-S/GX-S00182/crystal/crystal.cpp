#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,ans;LL a[500010],s[500010],m;
LL calc(int x){
    LL res=2e18;
    for(int i=x;i<=n;i++){
        res=min(res,a[i]*x-s[i]+s[i-x]);
    }
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int L=0,R=n+1;
    while(L+1<R){
        int M=(L+R)>>1;
        if(calc(M)<=m)
            L=M;
        else
            R=M;
    }
    printf("%d\n",L);
}
