#include<bits/stdc++.h>
#define int long long
#define AKIOI dream but unreal
using namespace std;
int c,t,n,m;
vector<int> a[1000005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);\
	cout<<"WA";
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		
	}

	return 0;
}

