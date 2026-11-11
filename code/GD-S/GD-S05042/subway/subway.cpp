#include<bits/stdc++.h>
using namespace std;

namespace YiShengYS{

struct di{
	long long to,time;
};

const int cst=5e5+5; 
long long c,n,m,d,q,k,a,t,x,y,ms,mp,ans;
long long w[cst],ts[cst],tp[cst],szp[cst],szs[cst];
bool vs[cst],vp[cst];
vector<vector<di>> ptos(cst),stop(cst);
	
void fp(long long st,long long near,bool type){
	if(!type){
		for(long long i=0;i<szp[st];i++){
			if(!vs[ptos[st][i].to]){
				if(ts[ptos[st][i].to]==-1 || ts[ptos[st][i].to]>tp[st]+ptos[st][i].time) ts[ptos[st][i].to]=tp[st]+ptos[st][i].time;
				if(near<0 || (type?ts[near]:tp[near])>ts[ptos[st][i].to]){
					near=ptos[st][i].to;
					type=1;
				}
			}
		}	
	}else{
		for(long long i=0;i<szs[st];i++){
			if(!vp[stop[st][i].to]){
				if(tp[stop[st][i].to]==-1 || tp[stop[st][i].to]>ts[st]+stop[st][i].time) tp[stop[st][i].to]=ts[st]+stop[st][i].time;
				if(near<0 || (type?ts[near]:tp[near])>tp[stop[st][i].to]){
					near=stop[st][i].to;
					type=0;
				}
			}
		}
	}
	if(near<0){
		if(ms<n){
			for(int i=1;i<=n;i++){
				if((near<0 || near>ts[i]) && ts[i]>=0) {
					near=i;
					type=1;
				}
			}
		}
		if(mp<m){
			for(int i=1;i<=m;i++){
				if((near<0 || near>tp[i]) && tp[i]>=0){
					near=i;
					type=0;
				}
			}
		}
	}
	if(near<0) return;
	(type?vs[near]:vp[near])=1;
	(type?ms:mp)++;
//	cout<<type<<" "<<near<<" "<<(type?ts[near]:tp[near])<<"\n";
//	cout<<ms<<" "<<mp<<"\n";
	fp(near,-1,type);
	return;
}
	
int main(){
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=0;j<k;j++){
			scanf("%lld%lld",&a,&t);
			stop[i].push_back({a,t});
			szs[i]++;
			ptos[a].push_back({i,t});
			szp[a]++;
		}
	}
//	for(long long i=1;i<=m;i++){
//		for(long long j=0;j<szp[i];j++){
//			printf("%lld %lld  ",ptos[i][j].to,ptos[i][j].time);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(long long i=1;i<=n;i++){
//		for(long long j=0;j<szs[i];j++){
//			printf("%lld %lld  ",stop[i][j].to,stop[i][j].time);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(long long i=1;i<=m;i++){
//		printf("%lld ",w[i]);
//	}
//	printf("\n");
	for(int i=0;i<q;i++){
		scanf("%lld%lld",&x,&y);
		memset(ts,-1,sizeof(ts));
		memset(tp,-1,sizeof(tp));
		memset(vs,0,sizeof(vs));
		memset(vp,0,sizeof(vp));
		tp[x]=0;
		vp[x]=1;
		ms=0;
		mp=0;
		fp(x,-1,0);
//		for(int i=1;i<=m;i++){
//			printf("%lld ",tp[i]);
//		}
//		printf("  ");
//		for(int i=1;i<=n;i++){
//			printf("%lld ",ts[i]);
//		}
//		printf("\n");
//		printf("%lld\n",tp[y]);
		ans=w[x]+tp[y]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}


}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	YiShengYS::main();
	return 0;
}
