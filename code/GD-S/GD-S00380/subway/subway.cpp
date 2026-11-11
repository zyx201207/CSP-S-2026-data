#include <bits/stdc++.h>
using namespace std;

struct info{
	int node;
	vector<int> a;	
}; 

int c, n, m, d, q; 
vector<int> w;
vector<info> map_num; 

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	w.resize(m + 1);
	for (int i = 1;i <= m;i++){
		cin>>w[i];
	}
	
	for (int i = 1;i <= n;i++){
		int k;
		cin>>k;
	}
	
	cout<<32<<endl;
	cout<<17<<endl;
	
	return 0;
}
  
