#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=2e6+5;
ll c,t,n,d,x[MAXN],len[MAXN],minx=INT_MAX,ans;
ll dfs(ll m,ll jump,ll dep){
	if(m<=n) return dep;
	dfs(m+jump,jump,dep+1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		minx=INT_MAX;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=d;i++){
			len[i]=dfs(x[1],i,1);
			minx=min(minx,len[i]);
		}
		ans=d;
		for(int i=1;i<=d;i++){
			if(minx!=len[i]) ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
