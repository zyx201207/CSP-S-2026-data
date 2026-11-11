#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>c[500010],p[500010];
int w[500010],k[500010];
ll d[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _,n,m,o,q,x,y;
	cin>>_>>n>>m>>o>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			c[x].push_back(i),p[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)d[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int xx=0;xx<c[i].size();xx++){
			int x=c[i][xx],px=p[i][xx];
			for(int yy=xx+1;yy<c[i].size();yy++){
				int y=c[i][yy],py=p[i][yy];
				d[x][y]=d[y][x]=min(d[x][y],(ll)px+py);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<d[i][j]<<" ";
//		cout<<"\n";
//	}
//	cout<<"--------------\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<d[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		cin>>x>>y;
		ll ans=w[x]+w[y],mn=1e18;
		for(int i=0;i<c[x].size();i++){
			for(int j=0;j<c[y].size();j++){
				mn=min(mn,(ll)p[x][i]+p[y][j]+d[c[x][i]][c[y][j]]);
			}
		}
		cout<<ans+mn<<"\n";
	}
	return 0;
}
