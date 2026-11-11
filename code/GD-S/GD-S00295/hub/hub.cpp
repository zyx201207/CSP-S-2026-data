#include<bits/stdc++.h>
using namespace std;
vector<int> v[2000005];
int n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		for(int k=1;k<=n;k++)v[k].clear();
		cin>>n>>m;
		for(int k=1;k<=n;k++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ma=0,c=0;
		for(int k=1;k<=n;k++){
			if(ma<v[k].size())ma=v[k].size(),c=k;
		}
	}
	return 0;
}
