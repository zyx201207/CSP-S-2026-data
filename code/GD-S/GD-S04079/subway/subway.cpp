#include<bits/stdc++.h>
using namespace std;
struct str{
	int a;
	int t;
};	
int c,n,m,d,q;
vector<str> ve[505];
vector<int> mm;
bool done[505];
priority_queue<int,vector<int>,greater<int> > pq;
void dfs(int k,int l,int cnt,int x,int y){
	if(l>=ve[k].size()){
		return;	
	}
	if(ve[k][l].a==y){
		pq.push(cnt+ve[k][l].t+mm[y]);
				
	}
	dfs(k,l+1,cnt,x,y);
	for(int i=1;i<=n;i++){
		if(i==k||done[i])continue;
		for(int j=0;j<ve[i].size();j++){
			if(ve[i][j].a==ve[k][l].a){
				done[i]=1;
				dfs(i,j,cnt+ve[k][l].t+ve[i][j].t,x,y);
				done[i]=0;
			}
		}
	}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	mm.push_back(0);
	for(int i=1;i<=m;i++){
		int mmm; 
		cin>>mmm;
		mm.push_back(mmm);
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int a,t;
			cin>>a>>t;
			ve[j].push_back({a,t});
		}	
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		vector<str> kk;
		for(int j=1;j<=n;j++){
			for(int v=0;v<ve[j].size();v++){
				if(ve[j][v].a==x)kk.push_back({j,v});
	
			}
		
		}
		int minw=1e9;
		for(auto xx:kk){
			int a=xx.a;
			int b=xx.t;
			fill(done,done+n+1,0);
			done[a]=1;
			dfs(a,b,ve[a][b].t+mm[x],x,y);
			minw=min(minw,pq.top());
			while(!pq.empty())pq.pop();
		}
		cout<<minw<<'\n';	
	}

	return 0;
}
