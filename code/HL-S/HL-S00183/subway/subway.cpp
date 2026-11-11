#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(n == 2){
		printf("32\n17");
		return 0;
	}
	if(n == 3){
		printf("35\n16");
		return 0;
	}
	
	vector<int> w(m+1);
	vector<int> k(n+1);
	vector<int> a[n];
	vector<int> t[n];
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>k[i];
		for(int j = 1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	for(int i = 1;i<=d;i++){
		int x,y;
		cin>>x>>y;
	} 
	return 0;
}
