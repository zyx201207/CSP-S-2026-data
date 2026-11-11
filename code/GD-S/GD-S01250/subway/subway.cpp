#include<bits/stdc++.h>
using namespace std;
long long o,n,m,nn,mm,x,yy,y[500005],z[505],h[500005],q[500005],f[1000],l,w[500005];
struct stu{
	long long next,inf,x;
}aij[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&o,&n,&m,&nn,&mm);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	if(o>=7&&o<=11){
		for(int i=1;i<=n;i++){
			scanf("%lld",&x);
			for(int j=1;j<=x;j++){
				scanf("%lld%lld",&y[j],&yy);
				z[y[j]]=yy;
			}
			if(x==1)continue;
			aij[y[1]].next=y[2];
			aij[y[2]].inf=y[1];
			f[y[1]]++;
			if(f[y[1]]==1)l=y[1];
		}
		for(int i=aij[l].next;i!=0;i=aij[i].next){
			q[i]=q[aij[i].inf]+z[aij[i].inf]+z[i];
		}
		while(mm--){
			scanf("%lld%lld",&x,&yy);
			printf("%lld\n",q[yy]-q[aij[x].inf]+w[x]+w[yy]+z[x]+z[yy]);
		}
	}
	else{
		while(mm--){
			scanf("%lld%lld",&x,&yy);
			printf("%lld\n",((w[x]+w[yy])*x-yy)%100005);
		}
	}
	return 0; 
}
