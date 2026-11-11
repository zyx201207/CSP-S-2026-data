#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500050];
long long ad[500050];
long long check(int l,int i,long long w){
    return (i-l+1)*w-(ad[i]-ad[l-1]);
}
int crystal(int l,int r,int i)
{
    while(l<r)
    {
        int mid=(l+r)>>1;
        long long w=check(mid,i,a[i]);
        //printf("mid=%d,w=%d\n",mid,w);
        if(w<=m)r=mid;
        else l=mid+1;
    }
    return i-r+1;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ad[i]=ad[i-1]+a[i];
        //printf("i=%d,%d\n",i,ad[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        //printf("a[%d]=%d\n",i,a[i]);
        if(a[i]==a[i+1])continue;
        //printf("i=%d\n",i);
        ans=max(ans,crystal(1,i,i));
        //printf("ans=%d\n",ans);
    }
    printf("%lld",ans);
}
