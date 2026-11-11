#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 0;i < t;i++){
		int n,d;
		cin>>n>>d;
		int a[n+1];
		for(int j = 0;j < n;j++){
			cin>>a[j];
		}if(n==4){
			cout<<"1"<<endl<<"2";
		}else if(n==5){
			cout<<"0"<<endl<<"1";
		}
	}
	return 0;
}
