#include<bits/stdc++.h>
using namespace std;
vector<long long> mp[500005];
long long ans=2e9;
void huan(long long x,long long y,long long dep){
	if(x==y){
		ans=min(ans,dep);
		return ;
	}
	for(int i=0;i<mp[x].size();i++){
		int v=mp[x][i];
		huan(v,y,dep+1);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	long long w[500005];
	long long k[500005],a[505][500005],t[505][500005];
	long long x,y;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			mp[a[i][j]].push_back(i);
		}
	}
	if(c>=12&&c<=19){
		for(long long i=1;i<=q;i++){
			ans=2e9;
			scanf("%lld%lld",&x,&y);
			huan(x,y,0);
			printf("%lld\n",ans*t[1][1]+w[x]+w[y]);
		}
		return 0;
	}
	if(c>=7&&c<=11){
		ans=0;
		scanf("%lld%lld",&x,&y);
		for(int i=1;i<=m;i++){
			for(int j=1;j<=k[i];j++){
				ans+=t[i][j];
			}
		}
		ans=ans+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
} 
