#include<bits/stdc++.h>
#define int long long
using namespace std;
struct h{
	int x,y,z;
	bool operator<(const h &b)const{
		return y>b.y;
	}
};
priority_queue<h>qq;
const int N=401;
int d[501][401][201];
int vis[501][401][201];
int v1[N][N];
int v[N];
vector<h>ve[N];
int c,n,m,dd,q,k;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;++i){
		cin>>v[i];
	}
	vector<pair<int,int> >sum;
	for(int i=1;i<=n;++i){
		cin>>k;
		sum.clear();
		for(int i=1;i<=k;++i){
			int x,y;
			cin>>x>>y;
			sum.push_back({x,y});
		}
		for(int j=0;j<sum.size();++j){
			v1[i][sum[j].first]=sum[j].second;
		}
		for(int j=0;j<sum.size();++j){
			for(int k=j+1;k<sum.size();++k){
				ve[sum[j].first].push_back({sum[k].first,0,i});
				ve[sum[k].first].push_back({sum[j].first,0,i});
			}
		}
	}
	for(int i=0;i<=m;++i){
		for(int j=0;j<=m;++j){
			for(int k=0;k<=n;++k){
				d[i][j][k]=1e18;
			}
		}
	}
	for(int i=1;i<=m;++i){
		qq=priority_queue<h>();
		d[i][i][0]=0;
		qq.push({i,0,0});
		while(!qq.empty()){
			auto qf=qq.top();
			qq.pop();
			if(vis[i][qf.x][qf.z])continue;
			vis[i][qf.x][qf.z]=1;
			for(auto to:ve[qf.x]){
				//cout<<qf.x<<' '<<qf.y<<' '<<qf.z<<' '<<to.x<<' '<<to.y<<' '<<to.z<<'\n';
				if(to.z==qf.z&&d[i][to.x][qf.z]>d[i][qf.x][qf.z]+to.y){
					d[i][to.x][qf.z]=d[i][qf.x][qf.z]+to.y;
					qq.push({to.x,d[i][to.x][qf.z],qf.z});
				}
			}
			for(int j=0;j<=n;++j){
				if(j==qf.z)continue;
				if(qf.z==0){
					if(v1[j][qf.x]){
						if(d[i][qf.x][j]>d[i][qf.x][qf.z]+v1[j][qf.x]){
						d[i][qf.x][j]=d[i][qf.x][qf.z]+v1[j][qf.x];
						qq.push({qf.x,d[i][qf.x][j],j});
						}
					}
				}
				else if((v1[qf.z][qf.x]!=0&&v1[j][qf.x])){
					if(d[i][qf.x][j]>d[i][qf.x][qf.z]+v1[qf.z][qf.x]+v1[j][qf.x]){
						d[i][qf.x][j]=d[i][qf.x][qf.z]+v1[qf.z][qf.x]+v1[j][qf.x];
						qq.push({qf.x,d[i][qf.x][j],j});
					}
				}
			}
		} 
	}
	while(q--){
		int x,y,sum=1e18;
		cin>>x>>y;
		for(int i=1;i<=n;++i){
			sum=min(sum,d[x][y][i]+d[y][y][i]+v[x]+v[y]);
		}
		cout<<sum<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
