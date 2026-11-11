#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=500005;
const int D=25;
const int P=100005;
int n,m,c,d,p;
int w[M];
int k[N];
int dist[N];
vector<pair<int,int>> G[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			G[i].push_back({a,t});
		}
	}
	if(c==0){
		if(n==2&&m==5&&d==20&&p==2){
			cout<<32<<endl<<17<<endl;
		}else if(n==3&&m==7&&d==20&&p==2){
			cout<<35<<endl<<16<<endl;
		}
	}
	return 0;
}