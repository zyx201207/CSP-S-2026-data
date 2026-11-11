//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;

int w[MAXN];
vector<pair<int,int> > v[MAXN];
int ans[505][505];
map<int,int> tim[MAXN];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _,n,m,d,q;
	scanf("%lld %lld %lld %lld %lld",&_,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for (int i=1;i<=n;i++){
		int num;
		scanf("%lld",&num);
		for (int j=1;j<=num;j++){
			int a,b;
			scanf("%lld %lld",&a,&b);
			v[a].push_back({i,b});
			tim[a][i]=b;
		}
	}
	for (int i=1;i<=500;i++) for (int j=1;j<=500;j++) if (i!=j) ans[i][j]=1e18;
	for (int i=1;i<=m;i++)
		for (int j=0;j<v[i].size();j++)
			for (int k=j+1;k<v[i].size();k++){
				ans[v[i][j].first][v[i][k].first]=min(ans[v[i][j].first][v[i][k].first],v[i][j].second+v[i][k].second);
				ans[v[i][k].first][v[i][j].first]=ans[v[i][j].first][v[i][k].first];
			}
	
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			if (i!=k)
				for (int j=1;j<=n;j++)
					if (j!=k and j!=i)
						ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
	
	for (int i=1;i<=q;i++){
		int a,b;
		scanf("%lld %lld",&a,&b);
		if (a==b){
			printf("0\n");
			continue;
		}
		int ans1=1e18;
		for (auto j:v[a])
			for (auto k:v[b])
				ans1=min(ans1,tim[a][j.first]+ans[j.first][k.first]+tim[b][k.first]);
		printf("%lld\n",ans1+w[a]+w[b]);
	}

	return 0;
}

