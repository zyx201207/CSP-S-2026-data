#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct wsw{
    int w;
    long long total;
    long long l,r;
}num[N],rnk[N];
long long len=0;
int n;
long long dis[2*N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&num[i].total);
        len+=num[i].total;
        num[i].l=num[i-1].r+1;
        num[i].r=num[i].l+num[i].total-1;
        dis[i]=num[i].r;
        char a;
        scanf("%c",&a);
        while(a<'a'||a>'z') scanf("%c",&a);
        num[i].w=a-'a'+1;
    }
    for(int i=1;i<=n;i++){
        rnk[i].l=rnk[i-1].r+1;
        rnk[i].r=rnk[i].l+num[n-i+1].total-1;
        rnk[i].total=num[n-i+1].total;
        rnk[i].w=num[n-i+1].w;
        dis[n+i]=rnk[i].r;
    }
    sort(dis+1,dis+(2*n)+1);
    int f1=1,f2=1;
    long long ans=0;
    for(int i=1;i<=2*n;i++){
        long long nwl=dis[i-1]+1,nwr=dis[i];
        while(!(num[f1].l<=nwl&&nwr<=num[f1].r)) f1++;
        while(!(rnk[f2].l<=nwl&&nwr<=rnk[f2].r)) f2++;
        if(num[f1].w!=rnk[f2].w) ans+=nwr-nwl+1;
    }
    ans/=2;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}