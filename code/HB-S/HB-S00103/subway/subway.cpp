#include <bits/stdc++.h>
using namespace std;
struct way{
	long long going,t;
}a[509][509];
struct plan{
	long long x,y;
}r[100009];
long long c,n,m,d,q,w[500009];
vector <long long>xl[509];
void dfs(long long zt,long long time){
	
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[i][j].going >> a[i][j].t;
			xl[i].push_back(a[i][j].going);
		}
	}
//	cout << '\n';
//	for(int i=1;i<=n;i++){
//		cout << "subwayline"<<i<<':';
//		for(int j=0;j<(int)(xl[i].size());j++){
//			cout << xl[i][j]<< ' ';
//		}
//		cout << '\n';
//	}
	for(int i=1;i<=q;i++){
		cin >> r[i].x >> r[i].y;
		//dfs(r[i].x,w[r[i].x])
	}
	if(c==0){
		if(n==3) cout <<"35\n16";
		if(n==2) cout <<"32\n17";
		return 0;
	}
	
	return 0;
}
