//周泰丞 GZ-S00048
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],sum[500020],ans=0;
int check(int x,int y)
{

    long long cha=a[y]-a[x];
    long long need=sum[y]-sum[x]-(x-1)*cha;
    //printf("a[y]=%d,a[x]=%d,sum[y]=%d,sum[x]=%d\ncha=%d,need=%d\n",a[y],a[x],sum[y],sum[x],cha,need);
    if(need>m)return 1;
    if(need==m)return 2;
    return 3;
}
void erfen(long long l,long long r)
{
    int R=r,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        //printf("l=%d,r=%d,mid=%d\n",l,r,mid);
        if(check(mid,R)==1)
        {
            l=mid+1;

        }
        else if(check(mid,R)==2){
                    break;
                }
        else
        {
            r=mid-1;
        }
    }
    ans=max(ans,1ll*(R-mid+1));

    return ;
}
int main()
{
    freopen("crystal4.in","r",stdin);
    freopen("crystal4.out","w",stdout);
	cin>>n>>m;
	sum[1]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	for(int i=2;i<=n;i++)
    {
        erfen(1,i);
        //printf("i=%d\n",i);
    }
	printf("%lld",ans);
	return 0;
}
