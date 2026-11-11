#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> now;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1,val;i<=n;i++){
		scanf("%d",&val);
		now.push_back(val);
	}
	for(int bit=29;~bit;bit--){
		vector<int> nxt[2];
		for(auto val:now)
			nxt[val>>bit&1].push_back(val);
		if((int)nxt[1].size()>=m)
			ans+=(1<<bit),now=nxt[1];
	}
	printf("%d",ans);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	for(;T;T--) solve();
}

