#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int ans,n,m,a[N],num[N];
int read()
{
    char c=getchar();int x=0,flag=1;
    while(c<'0'||c>'9'){if(c=='-'){flag=-1;}c=getchar();}
    while(c<='9'&&c>='0'){x=x*10+c-'0';c=getchar();}
    return x*flag;
}
int check(int x)
{
    int sum=0;
    for(int i=1;i+x-1<=n;i++)
    {
		sum=0;
        sum=a[i+x-1]*x-(num[i+x-1]-num[i-1]);
        if(sum<=m)
			return 1;
    }
    return 0;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        num[i]=num[i-1]+a[i];
    int l=0;int r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }
    printf("%lld",ans);
    return 0;
}
