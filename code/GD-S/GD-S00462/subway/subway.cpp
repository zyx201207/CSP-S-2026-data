#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
vector<int>a[510];
vector<int>t[510];
vector<int>e[N];
int dis[N];
int vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int len=0;
		for(int j=1;j<=k;j++){
			int x,y;
			len++;
			cin>>x>>y;
			a[i].push_back(x);
//			e[a[i][len-1]].push(back(x));
//			e[x].push(back(e[a[i][len-1]]));
			t[i].push_back(y);
			ans+=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<0<<"\n";
	}
	return 0;
}
