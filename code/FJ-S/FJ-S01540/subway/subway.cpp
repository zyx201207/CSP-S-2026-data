#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000001],k[1000001],a[509][2001],t[509][2001],x,y,ans,v[509][2001],u[509][2001];
struct stu{
	long long x,y,z;
};
vector<stu> h[1000001];
void dfs(long long k,long long sum,long long zan,long long next,long long next2) {
	if(k==y) {
		if(zan!=next2) sum+=t[next2][u[next2][next]]+t[zan][u[zan][next]];
		ans=min(ans,sum)+t[zan][u[zan][k]];
		return;
	}
	for(auto i : h[k]) {
		if(v[i.z][i.x]==1) continue;
		v[i.z][i.x]=1;
		if(zan==next2) dfs(i.x,sum,i.z,k,zan);
		else dfs(i.x,sum+t[next2][u[next2][next]]+t[zan][u[zan][next]],i.z,k,zan);
		v[i.z][i.x]=0;
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++) {
		cin>>k[i];
		for(long long j=1;j<=k[i];j++) {
			cin>>a[i][j]>>t[i][j];
			u[i][a[i][j]]=j;
			if(j>1) {
				h[a[i][j-1]].push_back({a[i][j],t[i][j-1]+t[i][j],i});
			}
		}
	}
	while(q--) {
		cin>>x>>y;
		ans=1e12;
		memset(v,0,sizeof v);
		for(long long i=1;i<=n;i++) {
			if(u[i][x]==0) continue;
			dfs(x,w[x]+w[y]+t[i][u[i][x]],i,x,i);
		}
		if(ans==1e12) {
			swap(x,y);
			for(long long i=1;i<=n;i++) {
				if(u[i][x]==0) continue;
				dfs(x,w[x]+w[y]+t[i][u[i][x]],i,x,i);
			}
		} else {
			cout<<ans<<"\n";
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
