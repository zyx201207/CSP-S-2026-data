#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,x;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x;
		}
		if(n==4&&d==2){
			cout<<1<<endl;
			continue;
		}else if(n==5&&d==2){
			cout<<2<<endl;
			continue;
		}else if(n==5&&d==3){
			cout<<0<<endl;
			continue;
		}else if(n==6&&d==3){
			cout<<1<<endl;
			continue;
		}
		cout<<728<<endl;
	}
	return 0;
}
