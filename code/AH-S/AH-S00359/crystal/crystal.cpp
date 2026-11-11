#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5,INF=LLONG_MAX/3;
LL n,m,ans,a[N],pre[N];
inline LL read(){
	LL ans=0,neg=1;
	char c=getchar();
	while(c==' '||c=='\n'||c=='\r'){c=getchar();}
	if(c=='-')
	{neg=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+LL(c-'0');c=getchar();}
	return ans*neg;
}
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
    {
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }
    LL j=1;
    for(int i=1;i<=n;i++)
    {
        while(j<=i&&(a[i]*(i-j+1)-(pre[i]-pre[j-1]))>m)j++;
        ans=max(ans,i-j+1);
    }
    printf("%lld",ans);
	return 0;
}
