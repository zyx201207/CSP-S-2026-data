#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=(2e6+5),INF=LLONG_MAX/3;
LL c,T,n,d,x[N];
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
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
    c=read();T=read();
    while(T--)
    {
        n=read();d=read();
        LL ca=0;bool suca=1;
        for(int i=1;i<=n;i++)
        {
            x[i]=read();
            if(i>2&&x[i]-x[i-1]!=ca)
            {
                suca=0;
            }
            if(i==2)ca=x[i]-x[i-1];
        }
        if(suca)
        {
            LL step=d/ca;
            if(step>1)printf("%lld\n",max(0ll,n-(step+step-1)));
                else printf("0\n");
        }
        else printf("%lld\n",0ll);
    }
    return 0;
}
