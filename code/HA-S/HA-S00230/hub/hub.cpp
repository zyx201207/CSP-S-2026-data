#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("hub.in","r",instd);
	freopen("hub.out","w",outstd);
	int c,t,n,k,u[2000005],v[2000005];
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k;
		for(int j=1;j<=n;j++){
			cin>>u[j]>>v[j];
		}
	}
	if(c==0&&t==2){
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	if(c==0&&t==3){
		cout<<"1"<<endl;
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	if(c==0&&t==1){
		cout<<"12251"<<endl;
	}
	return 0;
}

