#include<bits/stdc++.h>
#define ll long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int N=2e6+5;

int c,t,n,nxt[N];
ll d,x[N],arr1[N],sum1[N],arr2[N],sum2[N],arr3[N],cnt[N];
inline ll read()
{
    int ret=0,fh=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch=='-') fh=-1;
    for(;isdigit(ch);ch=getchar())
        ret=ret*10+ch-'0';
    return ret*fh;
}
inline void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
ll qsum(int l,int r,int i)
{
    if(i==1) return sum1[r]-sum1[l-1];
    else return sum2[r]-sum2[l-1];
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--)
    {
        ll ans=0;
        n=read(),d=read();
        rep(i,1,n) x[i]=read();
        sort(x+1,x+1+n);
        //恰好1条路径
        per(i,n,1)
        {
            int pos=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
            //cout<<i<<":"<<pos<<endl;
            nxt[i]=pos;
            if(pos==i) continue;
            if(nxt[pos]>pos) arr1[i]+=nxt[pos]-nxt[pos-1];
        }
        per(i,n,1)
            if(nxt[nxt[i]]>nxt[i])
                sum1[i]=arr1[i]+sum1[nxt[i]];
        per(i,n,1)
            if(nxt[i]>i+1)
                arr2[i]+=nxt[nxt[i]-1]-nxt[nxt[i]-2];
        //rep(i,1,n) if(arr2[i]<0) cout<<"T"<<endl;
        per(i,n,1)
            if(nxt[i]>i+1)
                sum2[i]=arr2[i]+qsum(nxt[nxt[i]-2],nxt[nxt[i]-1],1);
        per(i,n,1)
            if(nxt[nxt[i]]>nxt[i])
                arr3[i]=sum2[i]+qsum(nxt[nxt[i]-1],nxt[nxt[i]],2);
        per(i,n,1)
            if(nxt[nxt[i]]>nxt[i])
                cnt[i]=arr3[i]+cnt[nxt[i]];
        rep(i,1,n) ans+=cnt[i];
        write(ans),putchar('\n');
        rep(i,1,n) arr1[i]=sum1[i]=arr2[i]=sum2[i]=arr3[i]=cnt[i]=nxt[i]=x[i]=0;
    }
    return 0;
}
//16:44
