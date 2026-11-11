//GZ_S00174 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long x[N],n,d;
vector<int> g;
int sy;
void dfs(int u,int step){
	if(u>sy) return ;
//	cout<<'*'<<u<<' '<<step<<'*';
	if(sy==u){
		g.push_back(step);
		return ; 
	} 
	
	for(int v=u+1;v<=n;v++){
		if(x[v]-x[u]<=d) dfs(v,step+1);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		memset(x,0,sizeof x);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				sy=v;
				dfs(u,0);
				
				sort(g.begin(),g.end());
				int cnt=0;
				for(auto i:g){
//					cout<<i<<'#';
					if(i==g[0]) cnt++;
				}
				g.erase(g.begin(),g.end());
//				cout<<u<<' '<<v<<' '<<' '<<sy<<' '<<cnt<<endl;
				if(cnt==2){
					ans++;
					
				} 
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}
