#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e5+10;

LL a[N],sum[N];

void read() {}
template <typename T,typename ...Args>
void read(T &x,Args &...args)
{
    x=0;  int f=1;  char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;  ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    x*=f;  read(args...);
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,ans=0;  LL m;  read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=i,mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d\n",ans);
    return 0;
}