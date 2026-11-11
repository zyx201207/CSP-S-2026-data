#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int n,d,x[N];
struct LS{
	long long Ls,lscd;
};
LS qx(int y,int z,int cd) {
	long long mincd=N;
	long long num=0;
	if(y>z) return {0,cd};
	if(y==z) return {1,cd};
	if(x[y]+d>=x[z]) return {1,cd+1};
	int i=y+1;
	while(x[y]+d>=x[i]) i++;
	for(i=i-1;i>=y+1;i--) {
		LS ls=qx(i,z,cd+1);
		if(ls.lscd>mincd) continue;
		mincd=min(ls.lscd,mincd);
		num+=ls.Ls;
	}
	return {num,cd};
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;
	scanf("%d%d",&C,&T);
	while(T--) {
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++) scanf("%d",&x[i]);
		long long num=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+2; j<=n; j++) {
				if(x[i]+d>=x[j])continue; 
				if(qx(i,j,0).Ls==2){
					num++;
				}
			}
		}
		printf("%lld\n",num);
	}
	return 0;
}
