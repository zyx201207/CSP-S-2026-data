#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
long long w[20005];
long long a[12501][12501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=2e18;
		}
		a[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		long long kl;
		scanf("%lld",&kl);
		vector<long long> lin;
		vector<long long> time;
		for(int k=1;k<=kl;k++){
			int l,ti;
			cin>>l>>ti;
			lin.push_back(l);
			time.push_back(ti);
		}
		for(int i=0;i<kl-1;i++){
			a[lin[i]][lin[i+1]]=min(a[lin[i]][lin[i+1]],time[i]+time[i+1]);
			a[lin[i+1]][lin[i]]=min(a[lin[i+1]][lin[i]],time[i+1]+time[i]);
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(int i=1;i<=p;i++){
		long long xr,yr;
		scanf("%lld%lld",&xr,&yr);
		printf("%lld\n",a[xr][yr]+w[xr]+w[yr]);
	}
	return 0;
}
