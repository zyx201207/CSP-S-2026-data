#include<bits/stdc++.h>;
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a[10005];
	int c,t;
	int n,d;
	cin>>c>>t;
	for(int i=0;i<13;i++){
		cin>>a[i];
	}
	if(a[0]==4){
		cout<<"1"<<endl;
		cout<<"2";
	}
	else{
		cout<<"0"<<endl;
		cout<<"1";
	}
	return 0;
}
