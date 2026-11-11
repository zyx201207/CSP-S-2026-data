#include<bits/stdc++.h>
using namespace std;
int n,a[200005],c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        char ch;
        scanf("%d %c\n",a+i,&ch);
        c[i]=ch-'a'+1;
    }
    int l=1,r=n,reml=a[1],remr=a[n];
    while(l<r){
        if(reml<remr){
            remr-=reml;
            if(c[l]!=c[r])ans+=reml;
            reml=a[++l];
        }
        if(reml==remr){
            if(c[l]!=c[r])ans+=reml;
            reml=a[++l];
            remr=a[--r];
        }
        if(reml>remr){
            reml-=remr;
            if(c[l]!=c[r])ans+=remr;
            remr=a[--r];
        }
    }
    printf("%lld",ans);
    return 0;
}