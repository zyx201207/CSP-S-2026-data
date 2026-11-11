//GZ-J00677 遵义市第十九中学 李俊希 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b,x,y;
	char a1,b1;
	cin>>a>>x>>a1>>b>>y>>b1;
	if(a==b){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(x==y){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(a1>='A' && b1>='A' && a1<='C' && b1<='C'){
		cout<<'1';
		if(a1-b1==1 || b1-a1==1){
			cout<<'1';
			return 0;
		}
		else{
			cout<<'0';
			return 0;
		}
	}
	if(a1>='D' && b1>='D' && a1<='E' && b1<='E'){
		cout<<"11";
		return 0;
	}
	cout<<"00";
	
	
	return 0;
}
