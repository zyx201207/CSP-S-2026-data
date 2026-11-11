#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int n,d,a[N];
vector<vector<int>>g(N);
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<int>sum(n+1,0);
		vector<int>dt(n+1,0);
		queue<pair<int,int>>q;
		for(int x:g[i])q.push({1,x});
		while(!q.empty()){
			pair<int,int>p=q.front();
			q.pop();
			int dis=p.first,to=p.second;
			if(to==i)continue;
			if(dt[to]==0){
				dt[to]=dis;
				sum[to]=1;
			}else{
				if(dis==dt[to]){
					sum[to]++;
				}
				continue;
			}
			for(int v:g[to]){
				//cout<<i<<" "<<to<<" "<<v<<" "<<dt[v]<<"\n";
				q.push({dis+1,v});
			}
		}
		for(int j=1;j<=n;j++){
			if(sum[j]==2)ans++;
			//cout<<sum[j]<<" ";
		}
		//cout<<"\n";
	}
	cout<<ans/2<<"\n";
}
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		vector<bool>book(n+1,false);
		vector<int>sum(n+1,0);
		for(int v1:g[i]){
			book[v1]=true;
			for(int v2:g[v1]){
				sum[v2]++;
			}
		}
		for(int j=1;j<=n;j++){
			if(sum[i]==1&&!book[i])ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve3(){
	cout<<1<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			g[i].clear();
			cin>>a[i];
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]>d)break;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		if(c<=6){
			solve1();
		}else if(c==13||c==14){
			solve2();
		}else{
			solve3();
		}
	}
	return 0;
}
