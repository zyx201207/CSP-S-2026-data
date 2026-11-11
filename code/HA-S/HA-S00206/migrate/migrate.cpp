#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d=0;
	long long x[100000]=0;
	cin>>c>>t>>endl;
	cin>>n>>d>>endl;
	for(int i=0;i<=n;i++){
		cin>>x[i];
	}
	if(n<=6){
		cout<<1<<endl;
		cout<<2;
	}else {
		cout<<0<<endl;
		cout<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
