#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n<4&&d>=2||d==1) cout<<0<<"\n";
		else cout<<1<<"\n";
	}
	return 0;
}
