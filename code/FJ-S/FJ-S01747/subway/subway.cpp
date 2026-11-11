#include<bits/stdc++.h>
using namespace std;
const int N=505,M=500005,S=20004;
int c,m,n,d,q,k;
long long w[M],tim[N][S],f[N][N],l[N][N];
bool e[N];
struct node{
	long long id,val;
}x;
vector<vector<int> > stop(M);
vector<vector<node> > line(N);
bool operator < (node a,node b){
	return a.val>b.val;
}
priority_queue<node> que;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int a;
		long long t;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			tim[i][a]=t;
			if(stop[a].size()){
				for(int u=0;u<stop[a].size();u++){
					f[i][stop[a][u]]=t+tim[stop[a][u]][a];
					f[stop[a][u]][i]=t+tim[stop[a][u]][a];
					//cout<<f[i][stop[a][u]]<<endl;
				}
			}
			stop[a].push_back(i);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(f[i][j]>0){
				line[i].push_back({j,f[i][j]});
			}
		}
	} 
	for(int i=1;i<=n;i++){
		//while(!que.empty())que.pop();
		memset(e,0,sizeof(e));
		que.push({i,0});
		while(!que.empty()){
			x=que.top(),que.pop();
			if(e[x.id])continue;
			l[i][x.id]=x.val;
			e[x.id]=1;
			for(auto j:line[x.id]){
				que.push({j.id,j.val+x.val});
			}
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	int x,y,ax,ay;
	long long ans;
	while(q--){
		ans=2e9;
		cin>>x>>y;
		for(int i:stop[x]){
			for(int j:stop[y]){
				if(l[i][j]<ans){
					ax=i,ay=j;
					ans=min(ans,l[i][j]);
				}
			}
		}
		if(x==y){
			cout<<0<<endl;
			continue;
		}else{
			ans+=w[x]+w[y]+tim[ax][x]+tim[ay][y];
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
