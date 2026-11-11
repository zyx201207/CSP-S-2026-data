#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long w[500010];
long long ans[510][510];
vector<pair<long long,long long>> station[500010];

int main(){
	for (int i=0;i<=500;i++){
		for (int j=0;j<=500;j++){
			ans[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		ans[i][i]=0;
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for (long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for (long long j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
//			line[i].push_back(make_pair(a,t));
			station[a].push_back(make_pair(i,t));
		}
	}
	for (long long k=1;k<=m;k++){
		for (long long i=0;i<station[k].size();i++){
			for (long long j=i+1;j<station[k].size();j++){
				long long x=station[k][i].first,y=station[k][j].first;
				ans[x][y]=ans[y][x]=min(ans[x][y],station[k][i].second+station[k][j].second);
			}
		}
	}
//	for (long long i=1;i<=q;i++){
//		long long x,y;
//		cin>>x>>y;
//		long long final_ans=0x3f3f3f3f3f3f3f3f;
//		for (long long i=0;i<station[x].size();i++){
//			for (long long j=0;j<station[y].size();j++){
//				final_ans=min(final_ans,cal(station[x][i].first,station[y][j].first)+w[x]+w[y]+station[x][i].second+station[y][j].second);
//			}
//		}
//		cout<<final_ans<<endl;
//	}
//	
	while (true){
		bool ok=false;
		for (long long i=1;i<=n;i++){
			for (long long j=i+1;j<=n;j++){
				for (long long k=1;k<=n;k++){
					if (ans[i][k]!=0x3f3f3f3f3f3f3f3f and ans[k][j]!=0x3f3f3f3f3f3f3f3f and ans[i][j]>ans[i][k]+ans[k][j]){
						ans[i][j]=ans[j][i]=ans[i][k]+ans[k][j];
						ok=true;
					}
				}
			}
		}
		if (!ok){
			break;
		}
	}
	for (long long i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		long long final_ans=0x3f3f3f3f3f3f3f3f;
		for (long long i=0;i<station[x].size();i++){
			for (long long j=0;j<station[y].size();j++){
				final_ans=min(final_ans,ans[station[x][i].first][station[y][j].first]+w[x]+w[y]+station[x][i].second+station[y][j].second);
			}
		}
		cout<<final_ans<<endl;
	}
	return 0;
}
