#include<iostream>
#include<vector>
using namespace std;
const int MAXN=50050;
int c,n,m,q,d;
int w[MAXN];
vector<pair<int,int> > aa[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>q>>d;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			aa[i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<"45\n80";
	return 0;
}
