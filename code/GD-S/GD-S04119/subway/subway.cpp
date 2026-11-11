#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,x,y;
int w[500005],k[501];
ll ans,dis[501][501];
struct Node{
	int a,t;
};
vector<Node>l[501];
vector<Node>p[500005];
bool cmp(Node x,Node y){
	return x.a<y.a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			Node tmp;
			cin>>tmp.a>>tmp.t;
			p[tmp.a].push_back({i,tmp.t});
			l[i].push_back(tmp);
		}
	}
	for(int i=1;i<=n;i++)sort(l[i].begin(),l[i].end(),cmp);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++){
			dis[i][j]=1e17;
			for(int c1=0,c2=0;c1<k[i]&&c2<k[j];c1++,c2++){
				if(l[i][c1].a==l[j][c2].a){
					dis[i][j]=min(dis[i][j],1ll*l[i][c1].t+l[j][c2].t);
				}
				else if(l[i][c1].a<l[j][c2].a)c2--;
				else c1--;
			}
			dis[j][i]=dis[i][j];
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==mid||i==j|j==mid)continue;
				if(dis[i][j]>dis[i][mid]+dis[mid][j])dis[i][j]=dis[i][mid]+dis[mid][j];
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e17;
		for(int i=0;i<p[x].size();i++){
			for(int j=0;j<p[y].size();j++){
				ans=min(ans,p[x][i].t+dis[p[x][i].a][p[y][j].a]+p[y][j].t);
			}
		}
		ans+=1ll*w[x]+w[y];
		cout<<ans<<'\n'; 
	}
	return 0;
}
