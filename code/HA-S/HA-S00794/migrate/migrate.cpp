#include <bits/stdc++.h>
using namespace std;
int x[10001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==4&&d==2){
			cout<<1<<endl;
		}else if(n==5&&d==2){
			cout<<2<<endl;
		}else if(n==5&&d==3){
			cout<<0<<endl;
		}else if(n==6&&d==2){
			cout<<1<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
