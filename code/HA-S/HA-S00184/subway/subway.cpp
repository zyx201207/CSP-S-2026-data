#include <bits/stdc++.h>
using namespace std;
map<int,set<int> > mp;
int b[300005];
struct node{
	int xx,yy;
};
node a[10005][22];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c, n, m, d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			a[i][j].xx=x;
			a[i][j].yy=y;
			
		}
		
	}
	while(q--){
		int xq,yq;
		cin >> xq >> yq;
		int sum=0;
		sum+=b[xq];
		sum+=b[yq];
		cout << sum << endl;
		
	}
	return 0;
}
