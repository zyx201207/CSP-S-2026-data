#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,t;
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		int x[n];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if(n<=3){
			cout<<0<<'\n';
			continue;
		}
		cout<<n/d;
	}
	return 0;
}
