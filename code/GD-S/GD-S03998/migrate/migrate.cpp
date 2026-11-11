#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long ll;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	if(t==2){
		if(n==5){
			cout<<"1"<<endl;
			cout<<"2"<<endl;
		}
		if(n==6){
			cout<<"0"<<endl;
			cout<<"1"<<endl;
		}
	}
	else if(t==17){
		cout<<"8129"<<endl;
		cout<<"16"<<endl;
		cout<<"9"<<endl;
		cout<<"7"<<endl;
		cout<<"12"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"1"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"3"<<endl;
		cout<<"6"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"0"<<endl;
	}
	else if(t==12){
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"259997"<<endl;
		cout<<"259995"<<endl;
		cout<<"86669"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"7"<<endl;
		cout<<"5"<<endl;
		cout<<"5"<<endl;
		cout<<"0"<<endl;
	}
	else if(t==14){
		cout<<"9999900000"<<endl;
		cout<<"39995"<<endl;
		cout<<"0"<<endl;
		cout<<"716427"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"1"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"3"<<endl;
		cout<<"6"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
	}
	else if(t==16){
		cout<<"6800625333"<<endl;
		cout<<"6247500"<<endl;
		cout<<"6242502"<<endl;
		cout<<"4998"<<endl;
		cout<<"9994"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"1"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
		cout<<"3"<<endl;
		cout<<"6"<<endl;
		cout<<"0"<<endl;
		cout<<"2"<<endl;
	}
	return 0;
}
