#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v[32];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;cin>>n>>m;
	//cerr<<((0xf0>>4)&1);
	for(int i=1;i<=n;++i){
		int x;cin>>x;
		for(int i=0;i<32;++i){
			if((x>>i)&1)v[i].push_back(x);
		}
	}
	for(int i=0;i<32;++i){
		sort(v[i].begin(),v[i].end(),greater<int>());
		if(v[i].size()>=m){
			int k=v[i][0];
			for(int j=1;j<m;++j)k&=v[i][j];
			ans=max(ans,k);
		}
	}
	cout<<ans;
	//cerr<<'\n'<<ans;
	return 0;
}
