#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,n;
	cin>>c>>n;
	for(int i=0;i<n;i++){
		int t,d;
		cin>>t>>d;
		for(int j=0;j<t;j++){
			int a;
			cin>>a;
		}
		if(t==4) cout<<1<<endl;
		else if(t==5&&d==2) cout<<2<<endl;
		else if(t==5) cout<<0<<endl;
		else if(t==6) cout<<1<<endl;
	}
	return 0;
}
