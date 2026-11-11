#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int r1;
	string r2;
	int x1;
	string x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	char R1=r2[2],R2=r2[1],X1=x2[2],X2=x2[1];
	if(X2==R2){
		if(((X1-2)<=R1)||((X1+2)>=R1)){
			cout<<1;
			if(((X1-2)<=R1)||((X1+2)>=R1)){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(R1==X1-1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
