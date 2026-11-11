#include<bits/stdc++.h>
using namespace std;namespace Sol{int t,n,m,i,j,k,x,s,S,T,f[1001000],d[1010][1010];struct E{int x,y;}a,e[1001000];int _(int x){int&t=f[x];return t^f[t]?t=_(t):t;}
void M(){if(cin>>n>>t,n<13||n>14)for(;t--;cout<<s<<'\n',i=j=k=x=s=S=T=0,memset(f,0,n+5<<2)){
	for(cin>>n>>m;j^n;)for(i=++j;--i;d[i][j]=d[j][i]=n);for(i=n;--i;d[j][k]=d[k][j]=1,e[i]=E{j,k})cin>>j>>k;for(k=n;k;--k)for(i=n;i;--i)for(j=n;j;--j)x=d[i][k]+d[k][j],d[i][j]>x?d[i][j]=x:0;
	for(s=n,x=2<<n;x-=2;)if(m==__builtin_popcount(x)){for(i=n;i;--i)f[i]=i;for(;++i^n;x&1<<a.x&&x&1<<a.y?f[_(a.x)]=_(a.y):0)a=e[i];for(i=x,j=0;i;i&=i-1)j|=1<<_(__builtin_ctz(i));
	if(j&=j-1,j&j-1)continue;for(i=n,S=0;i;--i,S<T?S=T:0)for(k=x,T=n;k;k&=k-1)T=min(T,d[i][__builtin_ctz(k)]);s>S?s=S:0;}
}else for(;t--;cout<<(m^n?max((n+4>>1)-m>>2,0)+1:0)<<'\n')for(cin>>n>>m,i=n;i--;cin>>j>>k);}
}int main(){return freopen("hub.in","r",stdin),freopen("hub.out","w",stdout),ios::sync_with_stdio(0),cin.tie(nullptr),Sol::M(),0;}