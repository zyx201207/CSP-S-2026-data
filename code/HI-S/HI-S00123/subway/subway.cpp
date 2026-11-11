#include<bits/stdc++.h>
using namespace std;
int w[1010],k[1010];
int a[1010][1010],t[1010][1010];
vector<int> vec[1010];
int init(int x,int y){
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin>> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin>> k[i];
		for(int j = 1;j <= k[i];j++){
			cin>> a[i][j] >> t[i][j];
			vec[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>> x >> y;
		cout<< init(x,y) << "\n";
	}
	return 0;
}
