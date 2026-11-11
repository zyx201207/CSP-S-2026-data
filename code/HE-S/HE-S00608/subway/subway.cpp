#include<bits/stdc++.h>
using namespace std;

int const N=1e5+5; 
long long time1[510];
long long zt[505][N];
long long walk[510];
long long walk1[505][N];
long long k1[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	scanf("%lld",&c);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&d);
	scanf("%lld",&q);
	long long sum=0;
	for(long long i=1;i<=m;i++){
		scanf("%lld",&time[i]);
	}
	int x1=1;
	memset(walk,0,sizeof(walk));
	while(n--){
		long long k;
		scanf("%lld",&k);
		k1[x1]=k;
		for(int i=1;i<=k;i++){
			scanf("%lld",&zt[x1][i]);
			long long wt;
			scanf("%lld",&wt);
			walk[zt[x1][i]]+=wt;
			walk1[i][zt[x1][i]]=wt;
		}
		x1++;
	}
	while(q--){
		bool f=false;
		long long minn=INT_MAX;
		long long ss,ls;
		scanf("%lld",&ss);
		scanf("%lld",&ls);
		sum+=time1[ss]+=time1[ls];
		for(int i=1;i<=x1;i++){
			for(int j=1;j<=k1[i];j++){
				if(zt[i][j]==ss){
					sum+=walk1[i][ss];
					continue;
				}
				if(zt[i][j]==ls){
					sum+=walk1[i][ls];
					f=true;
					break;
				}
			}
			if(f){
				break;
			}
			
		}
		minn=min(sum,minn);
		printf("%lld\n",minn);
		sum=0;
	}
	
	return 0;
}
