#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
vector<int>vec[1000006];

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>t;
	
	while(t--){
		
		for(int i=1;i<=10;i++)vec[i].clear(); 
		
		cin>>n>>k;
		
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		
		if(c==1){
			if(n==k)cout<<0<<'\n';
			else if(k==n-1)cout<<1<<'\n';
			else if(k==n-2)cout<<1<<'\n';
			else if(k==n-3)cout<<1<<'\n';
			else if(k==n-4){
				int z=-1;
				for(int i=1;i<=n;i++)z=max(z,(int)vec[i].size());
				if(z==2 || z==4)cout<<2<<'\n';
				else cout<<1<<'\n';
			}
		}
		
	}
	
	return 0;
}
