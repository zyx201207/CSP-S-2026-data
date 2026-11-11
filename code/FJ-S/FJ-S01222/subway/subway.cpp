#include <bits/stdc++.h> 
using namespace std;
const long long M=5e5+78;
vector <long long> a[M],t[578];
long long c,n,m,d,Q,w[M],k[578],ans,vis[M],k1;
bool fs(long long x,long long y){
	for(long long i=0;i<a[x].size();i++){
		for(long long j=0;j<a[y].size();j++){
			if(a[x][i]==a[y][j]){
				k1=a[x][i];
				return true;
			}
		}		
	}
	return false;
}
void dfs(long long x,long long y){
	ans+=w[x]+w[y];
	if(fs(x,y)){
		ans+=t[k1][x-1]+t[k1][y-1];
		return;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]>1){
			for(long long j=1;j<=n;j++){
				bool cmp1=fs(x,j);
				long long u1=t[k1][x-1]+t[k1][j-1];
				ans+=u1;
				bool cmp2=fs(y,j);
				long long u2=t[k1][j-1]+t[k1][y-1];
				ans+=u2;
				if(cmp1&&cmp2) return;
				else{
					ans-=u1+u2;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&Q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			long long x_1,x_2;
			scanf("%lld %lld",&x_1,&x_2);
			vis[x_1]++;
			a[x_1].push_back(i);
			t[i].push_back(x_2);
		}
	}
	while(Q--){
		long long y_1,y_2;
		ans=0;
		scanf("%lld %lld",&y_1,&y_2);
		dfs(y_1,y_2);
		printf("%lld\n",ans);
	}
	return 0;
}
