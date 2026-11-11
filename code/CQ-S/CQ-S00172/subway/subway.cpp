#include<bits/stdc++.h>
using namespace std;
//#define int long long;
int w[20005];
struct node{
	int x,y;
};
vector<node> v[20005];
long long dis[505][20005];
int c,n,m,d,q;
void spfa(int s){
	dis[s][m+s]=0;
	queue<int> q;
	q.push(m+s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(node e:v[x]){
			if(dis[s][x]+e.y<dis[s][e.x]){
				dis[s][e.x]=dis[s][x]+e.y;
				q.push(e.x);
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int x,y;
			cin>>x>>y;
			v[i+m].push_back({x,y});
			v[x].push_back({i+m,y});
//			cout<<i+m<<" "<<x<<" "<<y<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+m;j++){
			dis[i][j]=1e18;
		}
	}
//	cout<<mp[1];
	
	for(int i=1;i<=n;i++){
		spfa(i);
//		for(int j=1;j<=n+m;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(node e:v[x]){
			long long sum=e.y+dis[e.x-m][y];
			ans=min(ans,sum);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
//	while(1!=0){
//		
//	}
	return 0;
}
