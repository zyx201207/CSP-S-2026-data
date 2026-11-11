#include <bits/stdc++.h>
#define int long long
using namespace std;
const int max_m=5e5+5,max_n=1e3+5;
int c,n,m,d,q,w[max_m],dis[max_n][max_n];
vector<pair<int,int>>belong[max_m];
struct line{
	int len;
	vector<int>v;
	vector<int>t;
}a[max_n];
struct node{
	int to,w;
};
vector<int>v[max_n];
int cnt;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	cnt=n;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x,qwq=0;
		cin>>x;
		a[i].len=x;
		while(x--){
			int qwqx,qwqy;
			cin>>qwqx>>qwqy;
			a[i].v.push_back(qwqx);
			a[i].t.push_back(qwqy);
			belong[qwqx].push_back({i,qwq++});
		}
	}
	for(int i=1;i<=m;i++){
		if(belong[i].size()>1){
			cnt++;
			for(pair<int,int>j:belong[i]){
				dis[j.first][cnt]=a[j.first].t[j.second];
				dis[cnt][j.first]=dis[j.first][cnt];
				
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			if(i!=j&&!dis[i][j]){
				dis[i][j]=1e18;
			}
		}
	}
	for(int k=1;k<=cnt;k++){
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<=cnt;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(pair<int,int>i:belong[x]){
			for(pair<int,int>j:belong[y]){
				ans=min(ans,dis[i.first][j.first]+a[i.first].t[i.second]+a[j.first].t[j.second]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
