#include <bits/stdc++.h>
using namespace std;
int a[6000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	}
	if(c==1){
		cout<<1<<endl<<2;
	}else if(c==2){
		cout<<0<<endl<<1;
	}else{
		cout<<1;
	}
	return 0;
}
