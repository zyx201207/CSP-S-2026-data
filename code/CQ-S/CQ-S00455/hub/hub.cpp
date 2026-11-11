#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,a[1000005],b[1000005],mark[1000005],sum[1000005];
vector<int> g[1000005];
void dfs2(int x){
	for(auto i:g[x]){
		if(mark[i]||(a[i]==0)){
			continue;
		}
		mark[i]=1;
		dfs2(i);
	}
	return;
}
queue<int> q;
void bfs(){
	while(!q.empty()){
		int kkk=q.front();
		q.pop();
		mark[kkk]=0;
		for(auto i:g[kkk]){
			if(sum[i]>sum[kkk]+1){
				sum[i]=sum[kkk]+1;
				if(!mark[i]){
					mark[i]=1;
					q.push(i);
				}
			}
		}
	} 
	return;
}
void check(){
	int kkk=0;
	for(int i=1;i<=n;i++){
		kkk+=a[i];
	}
	if(kkk!=k){
		return;
	}
	for(int i=1;i<=n;i++){
		mark[i]=0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!mark[i]&&a[i]){
			mark[i]=1;
			dfs2(i);
			cnt++;
		}
	}
	if(cnt>2){
		return;
	}
	for(int i=1;i<=n;i++){
		sum[i]=1e9;
	}
	for(int j=1;j<=n;j++){
		mark[j]=0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]){
			q.push(i);
			mark[i]=1;
			sum[i]=0;
		}
	}
	bfs();
	int anss=0;
	for(int i=1;i<=n;i++){
		anss=max(anss,sum[i]);
	}
	ans=min(ans,anss);
	return;
}
void dfs(int now){
	if(now==n+1){
		check();
		return;
	}
	a[now]=1;
	dfs(now+1);
	a[now]=0;
	dfs(now+1); 
}
void kjq(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if(n<=15){
		dfs(1);
		cout<<ans<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	int kkk=7000;
	if(n<=300){
		kkk*=6;
	}
	if(n>50000){
		kkk=350;
	}
	for(int i=1;i<=kkk;i++){
		for(int j=1;j<=n;j++){
			int kkk=rand()%n+1,kkk2=rand()%n+1;
			swap(b[kkk],b[kkk2]);
		} 
		for(int j=1;j<=n;j++){
			mark[j]=0;
			a[j]=0;
		}
		for(int j=1;j<=k;j++){
			a[b[j]]=1;
		}
		int cnt=0;
		for(int j=1;j<=k;j++){
			if(!mark[b[j]]){
				cnt++;
				dfs2(b[j]);
			}
		}
		if(cnt>2){
			continue;
		}
		for(int j=1;j<=n;j++){
			mark[j]=0;
			sum[j]=1e9;
		}
		for(int j=1;j<=k;j++){
			q.push(b[j]);
			mark[b[j]]=1;
			sum[b[j]]=0;
		}
		bfs();
		int anss=0;
		for(int j=1;j<=n;j++){
			anss=max(anss,sum[j]);
		}
		ans=min(ans,anss);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		kjq();
	}
	return 0;
}
//rp++
//15pts
