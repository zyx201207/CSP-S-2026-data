#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c[1000005],st[1000005][25],s[1000005];
int qmax(int x,int y){
    int k=log2(y-x+1);
    return max(st[x][k],st[y-(1ll<<k)+1][k]);
}
int qsum(int x,int y){
    return s[y]-s[x-1];
}
int check(int x){
    for(int i=1;i<=a-x+1;i++){
        if(qmax(i,i+x-1)*x-qsum(i,i+x-1)<=b){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&a,&b);
    for(int i=1;i<=a;i++){
        scanf("%lld",&c[i]);
    }
    sort(c+1,c+a+1);
    for(int i=1;i<=a;i++){
        st[i][0]=c[i];
        s[i]=s[i-1]+c[i];
    }
    for(int j=1;(1ll<<j)<=a;j++){
        for(int i=1;i+(1ll<<j)-1<=a;i++){
            st[i][j]=max(st[i][j-1],st[i+(1ll<<(j-1))][j-1]);
        }
    }
    int l=1,r=a,ans;
    while(l<=r){
        int m=(l+r)>>1;
        if(check(m)){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    printf("%lld",ans);
    return 0;
}
