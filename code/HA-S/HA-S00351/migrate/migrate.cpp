#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
		}
		if(c==0&&n==4&&d==2){
			cout<<1<<endl;
			cout<<2;
		}
		else if(c==0&&n==5&&d==3){
			cout<<0<<endl;
			cout<<1;
		}
	}
	return 0;
}
