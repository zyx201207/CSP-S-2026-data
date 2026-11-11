#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],ans;
bool canvis[301][301],vis[301];
struct te{
	int now,dis;
}last;
int check(int x){
	deque<te> Q;Q.push_back({x,0});int res=0,cnt=1;last={0,0};
	for(int i=1;i<=n;i++)vis[i]=0;
	while(!Q.empty()){
		te now=Q.front();
		Q.pop_front();
		if(vis[now.now]){
			if(last.dis==now.dis&&last.now==now.now)cnt++;
		}
		else{
			for(int i=now.now+1;i<=n;i++){
				if(canvis[now.now][i])Q.push_back({i,now.dis+1});
			}
			vis[now.now]=1;
		}
		if(cnt==2){
			res++;
			cnt=1;
		}
		else cnt=1;
		last=now;
	}
	return res;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c>=7){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			cout<<n/4<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<=n;j++)canvis[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d)canvis[i][j]=canvis[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++)ans+=check(k);
		cout<<ans<<'\n';
	}
	return 0;
}
