#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long n,m,a[500010],qzh[500010],ans,l=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&(a[i]));
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        qzh[i]=qzh[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        while((l<i)&&((i-l+1)*a[i]-(qzh[i]-qzh[l-1])>m))
        {
            l++;
        }
        if(i-l+1>ans)
        {
            ans=i-l+1;
        }
    }
    printf("%lld",ans);
    return 0;
}
