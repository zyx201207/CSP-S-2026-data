#include<bits/stdc++.h>
using namespace std;
int n,m,o[214514][100],maw,fl[214514],h[214514],v[214514];
long long a,rans;
int ans[114];
void f(long long x,int y){
    int t=0;
    while(x){
        o[y][fl[y]]=(x&1);h[t]+=(x&1);
        x>>=1;fl[y]++;
        t++;
    }
    maw=max(maw,t);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        f(a,i);
    }
    for(int i=maw;i>=0;i--){
        if(h[i]<m) continue;
        ans[i]=1;
        for(int j=1;j<=n;j++){
            if(v[j]==1) continue;
            if(o[j][i]==0){
                v[j]=1;
                for(int k=0;k<=fl[j];k++) h[k]-=o[j][k];
            }
        }
    }
    int r=1;
    for(int i=0;i<=maw;i++){
        rans+=(ans[i]*r);
        r<<=1;
    }
    printf("%lld",rans);
    return 0;
}
