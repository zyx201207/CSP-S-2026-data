#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000006];
long long z[2000006],ct[2000006],id[2000006],ls,rs,as;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		as=0;
		scanf("%d%lld",&n,&d);
		int lg=1;
		for (int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			if (i>=3){
				if (x[i]-x[i-1]!=x[i-1]-x[i-2]) lg=0;
			}
		}
		if (lg){
			int ds=0;
			for (int i=2;i<=n;i++){
				if (x[i]-x[1]>d) break;
				ds=i-1;
			}
			if (ds>=2){
				printf("%d\n",max(0,n-ds-ds+1));
			}
			else{
				printf("0\n");
			}
		}
		else{
			for (int i=1;i<=n;i++){
				ls=0;
				rs=1;
				z[1]=i;
				ct[1]=0;
				id[1]=1;
				for (int j=i+1;j<=n;j++){
					while(rs>ls&&x[j]-x[z[ls+1]]>d){
						ls++;
					}
					if (ls==rs) break;
					rs++;
					z[rs]=j;
					ct[rs]=ct[ls+1]+1;
					id[rs]=id[ls+1];
					if (rs-ls>1&&ct[ls+2]==ct[ls+1]) id[rs]+=id[ls+2];
					if (rs-ls>2&&ct[ls+3]==ct[ls+1]) id[rs]+=id[ls+3];
					if (id[rs]==2) as++;
					if (id[rs]>3) id[rs]=3;
				}
			}
			printf("%lld\n",as);
		}
	}
	return 0;
}
// cant you cant you see me again
// let me 300+ ?