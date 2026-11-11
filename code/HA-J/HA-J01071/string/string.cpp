#include<bits/stdc++.h>
using namespace std;
int a[30];char b[30],b1[30];
int main(){
	freopen("travel.in","i")
	freopen("travel.out","w")
	char n2;
	int n,n3;string n1;
	cin>>n;
	n3=n-1;
		if(n==1){
		cout<<"0"<<endl;return 0;
	}
	for(int i=0;i<n;i++){	
	cin>>a[i]>>b[i];
	b1[i]=b[i];
	for(int j=0;j<a[i];j++){
		n1+=b[i];
		
	}
	}
	for(int z=n3;z>=0;z--){	
	if(b1[z]==b[z]){
		cout<<"0"<<endl;
	}

	return 0;
	}
}
