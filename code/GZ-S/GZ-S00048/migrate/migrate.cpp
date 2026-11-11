//÷‹Ã©ÿ© GZ-S00048
#include<bits/stdc++.h>
using namespace std;
long long a[2000020];
long long n,d,ans;
int erfen(long long k)
{
    int mid,l=1,r=n;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        //printf("l=%d,r=%d,mid=%d,%d\n",l,r,mid,k);
        if(k>a[mid])
        {
            l=mid+1;

        }
        else if(k==a[mid])
        {
            return mid;

        }
        else
        {
            r=mid-1;
        }
    }
    return mid;
}

void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
    {
        int f=erfen(a[i]+d)+1;
        int t=erfen(a[i]+d+d)-1;
        if(i+d+d>n)t=n;
        //printf("f=%d t=%d\n",f,t);
        ans+=max(0,(t-f+1));
    }
    printf("%lld\n",ans);
    ans=0;
	return;
}
int main()
{
    freopen("migrate1.in","r",stdin);
    freopen("migrate1.out","w",stdout);
	int T=1,c;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
