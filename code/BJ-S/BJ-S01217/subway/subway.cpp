#include<bits/stdc++.h>
using namespace std;
struct qwq{
	int vi,wi;
};
int C,n,m,d,q,w[500005];
vector<qwq>gl[505];
vector<int>ai[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int vj,wj;
			cin>>vj>>wj;
			gl[i].push_back({vj,wj});
			ai[vj].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
}
//ew8vy7wny 7w yfee79h6w94q960xjmxrehwty923%@#^@X%&TXH$XN#$#$@$#@%      @_@
