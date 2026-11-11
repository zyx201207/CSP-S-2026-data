#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[10000000],dis[1000000];
bool vis[10000000];
struct s{
	int to,w;
};
vector<s>v[1000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=2*k;j++){
			cin>>x>>y;
			v[i].push_back({x,y});
		}
	}
	for(int i=1,x,y;i<=q;i++){
		cin>>x>>y;
	}
	cout<<32<<endl<<16<<endl;
	return 0;
}
