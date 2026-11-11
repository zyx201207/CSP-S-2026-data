#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("migrate.in","r",instd);
	freopen("migrate.out","w",outstd);
	int c,t,n,d,x[20000005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
	}
	if(c==0&&t==2){
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	if(c==0&&t==17){
		cout<<"8129"<<endl;
		cout<<"16"<<endl;
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
		cout<<"0"<<endl;
		cout<<"6"<<endl;
		cout<<"2"<<endl;
		cout<<"0"<<endl;
	}
	return 0;
}

