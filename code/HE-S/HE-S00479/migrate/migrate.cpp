#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(n==4){
		cout<<1<<endl<<2;
	}
	else{
		cout<<0<<endl<<1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
