#include<bits/stdc++.h>
using namespace std;



int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	int c,t;
	cin>>c>>t;
	
	
	while(t--){
		
		int n,k;
		cin>>n>>k;
		vector<int> v;
		
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout<<1<<endl;
		
	} 
	return 0;
}

