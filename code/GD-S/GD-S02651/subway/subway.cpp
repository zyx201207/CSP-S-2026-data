#include<bits/stdc++.h>
using namespace std;

#define filename "subway"
#define ___usefile___

#ifdef ___usefile___
	ifstream ____cin____(filename".in");
	ofstream ____cout____(filename".out");
	#define cin ____cin____
	#define cout ____cout____
#endif

int c,n,m,d,q,x,y;

vector<int>w;

vector<vector<int>>edge;

void algo(){
	
}

int main(){
	cin>>c>>n>>m>>d;
	w.resize(m+5,0);
	edge.resize(m+5,vector<int>(n+5,-1));

	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		for(int j = 1;j <= k;j++){
			int a,t;
			cin>>a>>t;
			edge[a][i] = t;
		}
	}
	
	while(q--){
		cin>>x>>y;
		algo();
	}
	return 0;
}
