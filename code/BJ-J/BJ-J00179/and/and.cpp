#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=INT_MAX,maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    bool flag=1,flag1=1;
    for(int i=1;i<=n;i++){
        scanf("%d ",a+i);
        maxx=max(maxx,a[i]);
        if(a[i]&(a[i]+1))flag=0;
        if(a[i]!=i-1)flag1=0;
    }
    if(maxx<4){
        sort(a+1,a+1+n);
        for(int i=1;i<=m;i++)ans&=a[n-i+1];
        printf("%d",ans);
        return 0;
    }
    if(flag1){
        for(int i=1;i<=m;i++)ans&=a[n-i+1];
        printf("%d",ans);
        return 0;
    }
    if(flag){
        sort(a+1,a+1+n);
        for(int i=1;i<=m;i++)ans&=a[n-i+1];
        printf("%d",ans);
        return 0;
    }
    if(m==1){
        ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,a[i]);
        printf("%d",ans);
        return 0;
    }
    if(m==n){
        for(int i=2;i<=n;i++)a[i]&=a[i-1];
        printf("%d",a[n]);
        return 0;
    }
    if(n<=20){
        ans=0;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)!=m)continue;
            int res=INT_MAX;
            for(int j=0;j<n;j++){
                if(i>>j&1){
                    res&=a[j+1];
                }
            }
            ans=max(ans,res);
        }
        printf("%d",ans);
        return 0;
    }
    if(m==2){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%d",ans);
        return 0;
    }
    printf("0");
    return 0;
}