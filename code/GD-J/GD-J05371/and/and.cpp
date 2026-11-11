#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> a(n+1,vector<bool>(30));
	for(int i,x;i<=n;i++){
		cin>>x;
		for(int j=0;j<30;j++) a[i][j]=((x&(1<<j))>0);
	}
	vector<int> old,now;
	for(int i=1;i<=n;i++) now.emplace_back(i);
	int ans=0;
	for(int i=29;i>=0;i--){
		int cnt=0;
		for(auto j:now) 
			if(a[j][i]) cnt++;
		if(cnt<m) continue;
		ans+=(1<<i);
		old=now;
		now.clear();
		for(auto j:old)
			if(a[j][i]) now.emplace_back(j);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return 0;
}
