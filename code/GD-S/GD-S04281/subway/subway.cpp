#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],cnt,h[500005],res[10000005],dp[10000005];
long long co[10000005];
vector<pair<int,int> >g[10000005];
queue<int>qi;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	cnt=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		int la=0;
		for(int j=1,ai,ti,bi=0;j<=k;j++){
			cin>>ai>>ti;
			if(h[ai]){
				cnt++;
				bi=i+m*h[ai];
				res[bi]=ti;
				for(int k=0;k<h[ai];k++){
					g[ai].push_back({bi,ti+res[ai+m*k]});
					g[bi].push_back({ai,ti+res[ai+m*k]});
				}
			}
			else{
				res[ai]=ti;
			}
			h[ai]++;
			if(la!=0){
				if(bi){
					g[bi].push_back({la,0});
					g[la].push_back({bi,0});
				}
				else{
					g[ai].push_back({la,0});
					g[la].push_back({ai,0});
				}
			}
			if(bi){
				la=bi;
			}
			else{
				la=ai;
			}
			bi=0;
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		for(int j=1;j<=m;j++){
			co[j]=1e18;
			dp[j]=-1;
			for(int k=0;k<h[j];k++){
				co[j+k*m]=1e18;
				dp[j+k*m]=-1;
			}
		}
		for(int j=0;j<h[u];j++){
			qi.push(u+m*j);
			co[u+m*j]=0;
			dp[u+m*j]=res[u+m*j];
		}
		while(qi.size()){
			int ui=qi.front();
			qi.pop();
			for(pair<int,int> j:g[ui]){
				int vi=j.first,ci=j.second;
				if(co[vi]>co[ui]+ci){
					co[vi]=co[ui]+ci;
					dp[vi]=dp[ui];
					qi.push(vi);
				}
			}
		}
		long long ans=1e18,t=0;
		for(int j=0;j<h[v];j++){
			if(ans>co[v+m*j]){
				ans=co[v+m*j];
				t=dp[v+m*j]+res[v+m*j];
			}
		}
		cout<<ans+t+w[u]+w[v]<<"\n";
	}
	return 0;
}
