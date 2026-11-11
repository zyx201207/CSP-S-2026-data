#include<iostream>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int>>g(n+1);
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	}
	return 0;
} 
