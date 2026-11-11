#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
struct node{
	int a;
	int t;
};
int w[MAXN];
node g[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	int n;
	int m;
	int d;
	int q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		for(int j = 1;j <= x;j++){
			cin>>g[i][j].a>>g[i][j].t;
		}
	}
	while(q--){
		int x;
		int y;
		cin>>x>>y;
		cout<<10 * x + y<<endl;
	}
	return 0;
}

