#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int mx=5e5+100;
int a[mx];
int sum[mx];
int m;
int read()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
    return x*w;
}
void write(int x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
    return ;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=n&&a[i]==a[i+1]) continue;
        int l=1,r=i,pos=i;
        while(l<=r)
        {
            int mid=l+r>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) pos=mid,r=mid-1;
            else l=mid+1; 
        }
        maxn=max(maxn,i-pos+1);
    }
    cout<<maxn;
    return 0;
}