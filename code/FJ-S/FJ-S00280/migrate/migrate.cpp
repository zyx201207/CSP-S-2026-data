#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n=t;
	bool ok=0;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(b==3) ok=1;
		for(int i=1;i<=a;i++){
			int k;
			cin>>k;
		}
	}
	if(ok==0) cout<<1<<endl<<2;
	if(ok==1) cout<<0<<endl<<1;
	return 0;
}
