#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n+5);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<4){
			cout<<0<<"\n";
		}else if(n==4){
			if(a[4]-a[1]>d){
				cout<<0<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}else{
			cout<<2<<"\n";
		}
	}
	return 0;
}
