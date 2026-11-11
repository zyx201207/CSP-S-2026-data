#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;

vector<int> t[N];

void dfs(int x){
	
	
	
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int n;
	cin>>n;
	
	for (int i=1;i<=n;i++){
		
		int x,y; cin>>x>>y;
		t[x].push_back(y);
		t[y].push_back(x);
	
	} 
	
	for (int i=1;i<=n;i++){
		
		for (int j=1;j<=n;j++){
			
		}		
	}
	
	return 0;
	
}
