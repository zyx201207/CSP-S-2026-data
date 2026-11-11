#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5,maxm=3e5+5;
long long c,n,m,d,q,w[maxm],k[maxn],a[maxm],t[maxn],x,y,ji[maxm][maxn];
vector<long long>g[maxm];
vector<pair<long long,long long> >gg[maxn];
long long dfs(long long dian,long long xian,long long sum){
	long long ans=INT_MAX;
	if(dian==y)return sum;
	if(xian==0)
		for(int i=0;i<gg[dian].size();i++){
			long long _xian=gg[dian][i].first;
			ji[dian][_xian]=0;
			ans=min(ans,dfs(dian,gg[dian][i].first,0));
//			cout<<ans<<'\n';
		}
	else{
		//»»Ïß 
		for(int i=0;i<gg[dian].size();i++){
			long long _xian=gg[dian][i].first,ttt,tttt;
			if(_xian==xian)continue;
			for(int j=0;j<gg[dian].size();j++)
				if(gg[dian][j].first==xian){
					ttt=j;
					break;
				}
			for(int j=0;j<gg[dian].size();j++)
				if(gg[dian][j].first==_xian){
					tttt=j;
					break;
				}
			if(ji[dian][_xian]<=sum+gg[dian][ttt].second+gg[dian][tttt].second)continue;
			ji[dian][_xian]=sum+gg[dian][ttt].second+gg[dian][tttt].second;
			ans=min(ans,dfs(dian,_xian,ji[dian][_xian]));
		}
		//»»µã 
		for(int i=0;i<g[xian].size();i++){
			long long _dian=g[xian][i],ttt,tttt;
			if(_dian==dian)continue;
			for(int j=0;j<gg[dian].size();j++)
				if(gg[dian][j].first==xian){
					ttt=j;
					break;
				}
			for(int j=0;j<gg[_dian].size();j++)
				if(gg[_dian][j].first==xian){
					tttt=j;
					break;
				}
			if(ji[_dian][xian]<=sum+gg[dian][ttt].second+gg[_dian][tttt].second)continue;
			ji[_dian][xian]=sum+gg[dian][ttt].second+gg[_dian][tttt].second;
			ans=min(ans,dfs(_dian,xian,ji[_dian][xian]));
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
		for(int j=1;j<=k[i];j++)g[i].push_back(a[j]);
		for(int j=1;j<=k[i];j++)gg[a[j]].push_back({i,t[j]});
	}
	while(q--){
		memset(ji,0x3f3f3f3f,sizeof(ji));
		cin>>x>>y;
		cout<<dfs(x,0,0)+w[x]+w[y]<<'\n';
	}
	return 0;
}
