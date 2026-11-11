#include<bits/stdc++.h>
using namespace std;
const int N=2e6+100;
long long x[N],dis[N],num[N];
int n;
long long d;
long long read()
{
    long long sum=0;
    int f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') sum=sum*10+(ch-'0'),ch=getchar();
    return sum*f;
}
void write(long long num)
{
    if (num<0)
    {
        putchar('-');
        write(-num);
        return;
    }
    if (num>9) write(num/10);
    putchar(num%10+'0');
}
long long ans(int p)
{
    memset(dis,0x3f,sizeof(dis));
    memset(num,0,sizeof(num));
    dis[p]=0,num[p]=1;
    for (int i=p;i<=n;i++)
    {
        for (int j=lower_bound(x+1,x+n,x[i]-d)-x;j<i;j++)
        {
            if (x[j]<x[i]-d) break;
            if (dis[i]>dis[j]+1)
            {
                dis[i]=dis[j]+1;
                num[i]=num[j];
            }
            else if (dis[i]==dis[j]+1)
            {
                num[i]+=num[j];
            }
        }
    }
    long long cnt=0;
    for (int i=p;i<=n;i++)
    {
        if (num[i]==2) cnt++;
    }
    return cnt;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    c=read(),t=read();
    while (t--)
    {
        n=read(),d=read();
        for (int i=1;i<=n;i++) x[i]=read();
        long long sum=0;
        for (int i=1;i<=n;i++) sum+=ans(i);
        write(sum);
        putchar('\n');
    }
    return 0;
}
