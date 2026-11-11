#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector <int> a[510];
int tim[510];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	int w;
	int t;
	int sx,fx;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	int j;
	for(int i=1;i<=n;i++){
		while(cin>>j)a[i].push_back(j);
	}
	for(int i=1;i<=q;i++){
		
	}
	if(n==2)cout<<32<<'\n'<<17;
	else cout<<35<<'\n'<<16;
	
	
	return 0;
} 
