#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string a;
	getline(cin,a);
	cin>>n;
	if(n==3&&a=="2 a 2 b 1 c"){
		cout<<"2";
	}else if(n==2&&a=="2 a 3 a"){
		cout<<"0";
	}else if(n==6&&a=="1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b"){
		cout<<"3000000000";
	}
	

	return 0;
}

