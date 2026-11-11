#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,yyn=0,cdy,k=1,l=0;
long long jt[100000],txj[100000],lk[100000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&jt[i]);
	}
	for(int i=1;i<=n;i++){
		l+=1;
		txj[l]=k;
		scanf("%lld",&cdy);
		k+=(2*cdy)-1;
		for(int j=1;j<=(2*cdy);j++){
			scanf("%lld",lk[j]);
		}
	}
	return 0;
}
