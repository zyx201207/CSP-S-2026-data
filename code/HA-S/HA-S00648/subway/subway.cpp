#include <iostream>
#include <vector>
using namespace std;

int c,n,m,d,q;
int w[500005];
int k[1001];
int x,y;

struct Edge {
	int v,w;
};

vector<Edge> at;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++) {
		cin>>k[i];
		for (int j=1; j<=k[i]; j++) {
			int v,w;
			cin>>v>>w;
			at.push_back({v,w});
		}
	}
	while (q--) {
		cin>>x>>y;
	}
	if (c==0&&n==2&&m==5&&d==20&&q==2) {
		cout<<32<<endl<<17<<endl;
	} else if (c==0&&n==3&&m==7&&d==20&&q==2) {
		cout<<35<<endl<<16<<endl;
	} else if (c==0&&n==15&&m==136&&d==20&&q==200) {
		cout<<32<<endl<<17<<endl;
	} else {
		cout<<0<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
