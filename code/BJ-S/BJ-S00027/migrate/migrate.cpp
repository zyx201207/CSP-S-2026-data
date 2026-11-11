#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,ed,st;
long long a[400];
vector<long long> e[400];
long long cnt,minx;
void dfs(long long now,long long fa,long long d){
	if(now==ed){
		if(d<minx){
			cnt=1;minx=d;
		}else if(d==minx){
			cnt++;
		}
		return ;
	}
	for(long long v:e[now]){
		if(v==fa) continue;
		dfs(v,now,d+1);
	}
	return ;
}
void solve(){
	cin>>n>>d;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;
			if(abs(a[i]-a[j])<=d) e[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ed=j;st=i;cnt=0;minx=1e9;
			dfs(st,0,0);
			if(cnt==2){
				ans++;
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	    solve();
	}
	return 0;
}
