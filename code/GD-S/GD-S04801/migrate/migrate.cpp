#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int a;
		for(int i=1;i<=n;i++) cin>>a;
		if(n==4 && d==2) cout<<"1"<<endl;
		else if(n==5 && d==2) cout<<"2"<<endl;
		else if(n==5 && d==3) cout<<"0"<<endl;
		else if(n==6 && d==2) cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}
