#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL c,t;const LL N = 2e6+10;

//void dfs(vector<vector<LL>>){
//	
//}
//
//vector<vector<LL>> cal(LL st,LL ed){
//	vector<vector<LL>> res;
//	dfs(*res);
//}

//bool vis[2000010];
LL sum;
LL n,d;
vector<vector<LL>> all;
bool vis[N];

void clears(){
	for(LL i=1;i<=n;i++){
		vis[i]=0;
	}
}
void dd(LL st,LL ed,LL ko){
	if(ko==ed+1){
		vector<LL> res;
		for(LL i=1;i<=n;i++){
			if(vis[i]!=0)res.push_back(i);
		}
		all.push_back(res);
	}
	else{
		if(ko!=ed){
			vis[ko]=0;
			dd(st,ed,ko+1);
			vis[ko]=1;
			dd(st,ed,ko+1);
		}else{
			dd(st,ed,ko+1);
		}
	}
}

void solve(){
	LL ans=0;
	cin >> n >> d;
	vector<LL> x;
	x.resize(n);
	LL minn=0;
	LL isA=false;
	for(LL i=1;i<=n;i++){
		cin >> x[i];
		if(i==2)minn=x[i]-x[i-1];
		if(i>2)if(x[i]-x[i-1]!=minn)isA=false;
	}
	if(isA){
		if(d>=abs(minn)){
			cout << n/2 << '\n';
		}else{
			cout << 0 << '\n';
		}
		return;
	}
	
//	for(LL i=1,j=3;i<=n&&j<=n;i++,j++){
//		if(x[j]-x[i]<=d && x[i+1]-x[i]<=d && x[j]-x[i+1]<=d){
//			ans++;
//			cout << i << ' ' << j << '\n';
//		}
//	}
	for(LL i=1,j=4;i<=n-3,j<=n;i++,j++){
		if(x[j]-x[i]<=d)continue;
		if(x[i+2]-x[i]<=d && x[j]-x[i+2]<=d){
			if(x[j]-x[i+1]<=d)ans++;
		}
	}
	cout << ans << '\n';
	return;
	
}

int main(){
	freopen("migrate1.in","r",stdin);
	freopen("migrate1.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}

