#include<bits/stdc++.h>
#include<vector>
using namespace std ;
int a[500010];
vector <int> p[500010];
vector <int> q[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	while(n--){
		int z;
		cin>>z;
		for(int i=0;i<z;i++){
			int x,y;
			cin>>x>>y;
			p[x].push_back(y);
			p[y].push_back(x);
		}
	}
	return 0;
}
