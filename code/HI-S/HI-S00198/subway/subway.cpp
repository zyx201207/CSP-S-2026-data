#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int c,n,m,d,q;
int www[500005];
int k[505];
struct node{
	int to,w;
};
vector<pair<int,int> > contact[500005];
vector<node> edge[505];
int dis[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>www[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			contact[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e16;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=0;i<(int)contact[k].size();i++){
			for(int j=0;j<(int)contact[k].size();j++){
				int p1=contact[k][i].first,p2=contact[k][j].first;
				if(p1==p2) continue;
				int res=contact[k][i].second+contact[k][j].second;
				dis[p1][p2]=res;
				dis[p2][p1]=res;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		int ans=0,minn=1e16;
		ans=ans+www[s]+www[t];
		for(int i=0;i<(int)contact[s].size();i++){
			for(int j=0;j<(int)contact[t].size();j++){
				int tmp=ans;
				int pp1=contact[s][i].first,pp2=contact[t][j].first;
				int res1=contact[s][i].second,res2=contact[t][j].second;
				ans=ans+dis[pp1][pp2]+res1+res2;
				minn=min(minn,ans);
				ans=tmp;
			}
		}
		cout<<minn<<endl;
	}
	return 0;
}
