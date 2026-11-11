#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5e5+10;
struct node{
	ll id,time;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<vector<node>> line[510];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			node ne;
			cin>>ne.id>>ne.time;
			line[i].push_back(ne);
		}
	}

	return 0;
} 
