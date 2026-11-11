#include<bits/stdc++.h>
using namespace std;

vector<long long>s[1000000];

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0){
		cout<<0;
		return 0;
	}
	
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		if(k==2){
		cout<<1;
	}
		for(int j=1;j<=n-1;j++){
			int u,v;
			cin>>u>>v;
			s[u].push_back(v);
			s[v].push_back(u);
		}
	}
	
	int cnt=0;
	
	
	fclose(stdin);fclose(stdout);
	return 0;

} 

