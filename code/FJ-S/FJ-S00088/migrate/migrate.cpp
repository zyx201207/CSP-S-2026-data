#include<bits/stdc++.h>
using namespace std;
vector<int> e[2000005];
long long q,n,d,a[2000005],ans,sum,cur,p,vis[2000005];
void dfs(int u,int cnt,int s){
	if(u==s){
		if(ans>cnt){
			ans=cnt;
			sum=0;
		}
		if(ans==cnt) sum++;
		return;
	}
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v]) continue;
		dfs(v,cnt+1,s);
	}
	vis[u]=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>p>>q;
	while(q--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n>=10){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(abs(a[j]-a[i])<=d){
			e[i].push_back(j);
			e[j].push_back(i);
		}
		cur=0;
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
			ans=sum=1145141919;
			dfs(i,0,j);
			if(sum==2) cur++;
		}
		cout<<cur<<endl;
	}
	return 0;
}
//I am qu,I can not solve this problem./gunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmugunmu
//I love liuyin and xiadie.I hope I will get 2+1 luiyin
//if people's heart.is not.setisfied,people will.ride.valuable horse!?
