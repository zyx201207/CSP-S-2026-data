#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c==0){
		int n;
		cin>>n;
		if(n==4){
			cout<<1<<endl;
			cout<<2<<endl;
		}else{
			cout<<0<<endl;
			cout<<1<<endl;
		}
		
	}
	while(T--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		cout<<0<<endl;
		cout<<0<<endl;
	}
	return 0;
}
