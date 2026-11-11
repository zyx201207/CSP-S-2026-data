#include<cstdio>
#include<algorithm>
int n,m,a[200010],f[200010][31],s[200010][31],ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<30;j++)
            f[i][j]=((1<<j)&a[i])>0;
    for(int j=0;j<30;j++)
        for(int i=1;i<=n;i++)
            s[i][j]=s[i-1][j]+f[i][j];
    int l=1;
    for(int j=29;j>=0;j--){
        if(s[n][j]-s[l-1][j]>=m){
            ans+=(1<<j);
            int x=std::lower_bound(a+1,a+n+1,ans)-a;
            l=x;
        }
    }
    printf("%d\n",ans);
}
