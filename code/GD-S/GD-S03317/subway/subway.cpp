#include<bits/stdc++.h>
using namespace std;
//long long !!!!!!!!!!!
long long c,n,m,d,q,w[500005];
vector<pair<long long,long long> > s[500005];
long long e[505][505],dis[505][505];
int main(){
	//freopen("test.in","r",stdin);
	//freopen("mine.out","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//记得加上 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=1e18;
			if(i==j) e[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			long long st,zl;
			cin>>st>>zl;
			int si=s[st].size();
			for(int k=0;k<si;k++){
				e[i][s[st][k].first]=min(e[i][s[st][k].first],s[st][k].second+zl);
				e[s[st][k].first][i]=min(e[s[st][k].first][i],s[st][k].second+zl);
			}
			s[st].push_back({i,zl});
			//cout<<st<<" "<<i<<" test0\n";
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=e[i][j];
			if(i==j){
				dis[i][j]=e[i][j]=0;
			}
		}
	} 
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
			}
		} 
	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long minn=1e18;
		cin>>x>>y;
		//cout<<x<<y<<"\n";
		for(int j=0;j<s[x].size();j++){
			for(int k=0;k<s[y].size();k++){
				minn=min(minn,dis[s[x][j].first][s[y][k].first]+s[x][j].second+s[y][k].second);
				//cout<<s[x][j].first<<" "<<s[y][k].first<<" "<<dis[s[x][j].first][s[y][k].first]<<" "<<s[x][j].second<<" "<<s[y][k].second<<" test1\n";
			}
		}
		//cout<<i<<" "<<minn<<"  test\n";
		cout<<minn+w[x]+w[y]<<"\n";
	}
}
