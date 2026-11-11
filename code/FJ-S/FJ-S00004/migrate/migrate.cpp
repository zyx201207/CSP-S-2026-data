#include<bits/stdc++.h>
using namespace std;namespace Sol{using o=long long;const o N=2001000;o c,t,n,m,i,j,k,s,z,d[N],l[N],p[N],r[N],w[N],x[N];
void _(o u){for(o i=l[u];i^l[u+1];_(i++));r[u]=++z;}void P(o x,o k){for(;x<=z;x+=x&-x)w[x]+=k;}o Q(o x){o s=0;for(;x;x&=x-1)s+=w[x];return s;}
void M(){for(cin>>c>>t;t--;memset(d,i=j=k=s=z=0,n=n+5<<3),memset(l,0,n),memset(p,0,n),memset(r,0,n),memset(w,0,n)){
	for(l[1]=2,cin>>n>>m>>x[i=j=1];p[j]=i,j++^n;d[j]=i^j?d[i]+1:(l[i]=i+1,d[j-1]+(o)1e9))for(cin>>x[j];x[j]-x[i]>m;l[++i]=j);for(;i^j;l[++i]=j);
	if(c<7){for(i=0;i++^n;)if(i==p[i])_(i);for(i=0;i^n;)for(j=++i;j^n;s+=z==d[j]-d[i]+(r[i]<r[j])+2)for(z=0,k=++j;k>=i;--k)z+=o(r[i]<r[j])==o(r[i]<r[k])+o(r[k]<r[j]);cout<<s<<'\n';}
	else if(c<11){for(i=0;i++^n;)if(i==p[i])_(i);for(i=s=0;i^n;memset(w,0,z+5<<3))for(P(r[j=++i],1);j^n;
	s+=d[j]-d[i]+o(r[i]<r[j])+2==(r[i]<r[j]?j-i+1-Q(r[j]-1)+Q(r[i]):Q(r[i])-Q(r[j]-1)))P(r[++j],1);cout<<s<<'\n';}
	else z=n-p[n],cout<<(z<2?0:max(n-(z<<1)+1,0ll))<<'\n';
}}}int main(){return freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout),ios::sync_with_stdio(0),cin.tie(nullptr),Sol::M(),0;}