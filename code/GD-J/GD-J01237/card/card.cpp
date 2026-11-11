#include<bits/stdc++.h>
using namespace std;
long long n,m,i,l[500005],r[500005],b[500005],j,c[200005],d[500005],a[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&d[i]);
	l[n]=l[n+1]=n+1,r[n]=r[n+1]=n+1;
	for(i=n;i>=1;i--){
		if(c[d[i]])l[i-1]=i,j=c[d[i]],r[i]=c[d[i]];
		else l[i-1]=l[i],j=i;
		if(!c[d[i]])c[d[i]]=i;
		while(j<=n)b[j]++,b[l[j]]--,j=r[l[j]];
	}
	for(i=1;i<=n;i++)
		b[i]+=b[i-1],a[d[i]]+=b[i];
	for(i=1;i<=m;i++)
		printf("%lld ",a[i]);
	return 0;
}
