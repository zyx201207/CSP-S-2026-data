#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

namespace lyh{
	
	const int N = 1000;
	int c,T,n,k,dp[N][N][2],f[N];
	vector<int> g[N];
	
	void inlyh(){
		int x,y;
		cin>>n>>k;
		for(int i = 1;i < n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		return;
	}
	
	void dfs(int x){
		for(int i : g[x]){
			if(i == f[x]) continue;
			f[i] = x;
			
			dfs(i)
		}
		return;
	}

	void lyh(){
		inlyh();
		solyh();
		return;
	}
	
	void fre(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		return;
	}
	
}

int main(){
//	lyh::fre();
	lyh::lyh();
	return 0;
}
