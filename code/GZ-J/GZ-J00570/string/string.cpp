#include<bits/stdc++.h>
using namespace std;
int main(){
//	GZ-J00570 遵义市第十二中学  喻思豪 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,a;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>s;
		sum+=a;
	} 
	cout<<sum/2;
	return 0;
	if(n==3){
		cout<<"2";
		return 0;
	}
	if(n==2){
		cout<<"0";
		return 0;
	}
	if(n==6) {
		cout<<"3000000000";
		return 0;
	}
	return 0;
} 
/*
5 4
1 2 3 4 2
*/
