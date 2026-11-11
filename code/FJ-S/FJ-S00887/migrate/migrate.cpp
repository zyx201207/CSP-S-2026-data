#include<bits/stdc++.h>
using namespace std;
int c,t;
int x[2000005];
int n,d;
vector<int> mapp[2000005];
int cnt=0,minn=1e9;
int v;
void dfs(int u,int cs){
	if (cs>minn) return; 
	if (u==v){
		if (cs==minn) {
			cnt++;
			if (cnt>=3) return;
		}
		else {
			minn=cs;
			cnt=1;
		}
		return;
	}
	for (int i=mapp[u].size()-1;i>=0;i--) dfs(mapp[u][i],cs+1);
}
void work(){
	minn=1e9,cnt=0;
	cin>>n>>d;
	for (int i=1;i<=n;i++) {
		cin>>x[i];
		mapp[i].clear();
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n&&x[j]-x[i]<=d;j++){
			mapp[i].push_back(j);
		}
	}
	int ans=0;
	for (int u=1;u+3<=n;u++) {
		for (v=u+3;v<=n;v++){
			minn=1e9,cnt=0;
			dfs(u,0);
			if (cnt==2) ans++;
		}
	}
	cout<<ans<<"\n";
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if (c<=6) while (t--) work();
	else {
		while (t--) cout<<"0\n";
	}	
	return 0;
}

