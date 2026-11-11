#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int q=x[2]-x[1];
		if(q>=d){
			cout<<0<<endl;
			continue;
		}
	}
	return 0;
}
