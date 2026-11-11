#include <bits/stdc++.h>
using namespace std;
int c,t;
int ls[5010];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		for(int j=1;j<=n;j++){
			int a,b;
			cin>>a>>b;
			ls[b]=a;
			
		}
		cout<<ls[2]<<'\n';
	}
	
	
	return 0;
} 
