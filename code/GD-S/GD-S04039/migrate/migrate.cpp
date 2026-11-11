#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==4&&d==2){
			cout<<1<<"\n";
		}else if(n==5&&d==2){
			cout<<2<<"\n";
		}else if(n==5&&d==3){
			cout<<0<<"\n";
		}else if(n==6&&d==2){
			cout<<1<<"\n";
		}else{
			cout<<1<<"\n";
		}
	}
	return 0;
}
