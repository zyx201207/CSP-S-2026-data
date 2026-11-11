//GZ-S00013 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll c,t,i,n,k;
vector<vector<int>> g;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;

	if(c=0) i=0;
	else i=1;

	for(;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++) cin>>g[i][j];
	}
	ll ans=0;
	for(int i=1;i<=t;i++) cout<<ans;
	return 0;
}
