#include<bits/stdc++.h>
using namespace std;namespace Sol{using o=long long;o*D,*A,n,m,q,i,j,k,l,K,z,d[505][505],w[500100],p[500100],P[500100];struct t{o x,y;}a,b,e[500100];struct T{o x,y,z;}E[500100];
void M(){
	for(cin>>k>>n>>m>>l>>q;i^m;cin>>w[++i]);for(i=0;i++^n;)for(cin>>j;j--;++p[k],E[z++]=T{i,k,l})cin>>k>>l;for(i=m;i--;p[i]+=p[i+1]);for(;z--;e[--p[E[z].y]]=t{E[z].x,E[z].z});
	for(j=n;j;--j)for(i=j;--i;d[i][j]=d[j][i]=(o)1e18);for(k=m;k;--k)for(i=p[k-1];i^p[k];)for(a=e[j=--i],D=d[a.x];j^p[k];D[b.x]>z?D[b.x]=d[b.x][a.x]=z:0)b=e[--j],z=a.y+b.y;
	for(k=n;k;)for(i=n,D=d[k--];i;--i)for(j=n,l=D[i],A=d[i];j;--j)z=l+D[j],A[j]>z?A[j]=z:0;for(;q--;cout<<z+w[i]+w[j]<<'\n')
	for(z=(o)1e18,cin>>i>>j,k=p[i-1];k^p[i];)for(a=e[--k],l=p[j-1],D=d[a.x];l^p[j];z>K?z=K:0)b=e[--l],K=a.y+D[b.x]+b.y;
}}int main(){return freopen("subway.in","r",stdin),freopen("subway.out","w",stdout),ios::sync_with_stdio(0),cin.tie(nullptr),Sol::M(),0;}