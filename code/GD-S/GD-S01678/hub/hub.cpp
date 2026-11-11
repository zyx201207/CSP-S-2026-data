#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long c,n,m,a[N],b[N],f[N],sum,js,t,k,ans=1e18,x,y,z,hub[N],ltk,ltf[N],st[N];
vector<long long>e[N];
long long bfs(long long start){
	queue<pair<long long,long long>>q;
	q.push({start,0});
	while(!q.empty()){
		long long u=q.front().first,w=q.front().second;
		q.pop();
		if(f[u])
			continue;
		f[u]=1;
		if(hub[u])
			return w;
		for(long long i:e[u])
			q.push({i,w+1});
	}
	return 0;
}
void dfs(long long pos){
	if(ltf[pos]||!hub[pos])
		return;
	ltf[pos]=1;
	for(long long u:e[pos])
		dfs(u);
}
void solve(){
	cin>>n>>m;
	ans=1e18;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<(1<<n);i++){
		k=i,js=0,t=0,sum=0,ltk=0;
		for(int j=1;j<=n;j++)
			hub[j]=0;
		while(k){
			t++;
			if(k%2)
				hub[t]=1,js++,st[js]=t;
			k/=2;
		}
		if(js!=m)
			continue;
		for(int ii=1;ii<=n;ii++)
			ltf[ii]=0;
		for(int j=1;j<=n;j++)
			if(hub[j]&&!ltf[j])
				dfs(j),ltk++;
		if(ltk>2)
			continue;
		for(int j=1;j<=n;j++)
			if(!hub[j]){
				for(int ii=1;ii<=n;ii++)
					f[ii]=0;
				sum=max(sum,bfs(j));
			}
		if(sum<ans){
		//	for(int j=1;j<=js;j++)
		//		cout<<st[j]<<" ";
			ans=min(ans,sum);
		//	cout<<"\n"<<ans<<"\n";
		}
			
	}
	cout<<ans<<"\n";
	return;
}
void solvee(){
	cin>>n>>m;
	ans=1e18;
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++){
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i1=1;i1<=n;i1++){
		for(int i2=1;i2<=n;i2++){
			sum=0;
			if(i1==i2)
				continue;
			for(int i=1;i<=n;i++)
				hub[i]=0;
			hub[i1]=hub[i2]=1;
			for(int j=1;j<=n;j++)
				if(!hub[j]){
					for(int ii=1;ii<=n;ii++)
						f[ii]=0;
					sum=max(sum,bfs(j));
				}
			if(sum<ans)
				ans=min(ans,sum);
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	int T=1;
	cin>>T;
	while(T--){
		if(c<=3)
			solve();
		if(c==7)
			solvee();
	}
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
