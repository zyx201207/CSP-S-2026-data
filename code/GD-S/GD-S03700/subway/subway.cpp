#include<bits/stdc++.h>
#define zt first
#define ti second
using namespace std;
const int N=510,M=510*512/2;
int c,n,m,d,q,k,w[M];
vector <pair<int,int>>a[M];
queue <int> qt,init;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<s+e<<'\n';
	}
	return 0;
}
