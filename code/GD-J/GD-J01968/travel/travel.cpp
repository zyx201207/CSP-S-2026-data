#include<bits/stdc++.h>
using namespace std;
string cx1,cx2;
string zw1,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1;
	cin>>cx2>>zw2;
	if(cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(zw1[1]==zw2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	int flag=0;
	if(zw1[2]=='A'||zw1[2]=='B'||zw1[2]=='C'){
		if(zw2[2]=='A'||zw2[2]=='B'||zw2[2]=='C'){
			cout<<1;
			flag=1;
		}
	}else{
		if(zw1[2]=='F'||zw1[2]=='D'){
			if(zw2[2]=='F'||zw2[2]=='D'){
				cout<<1;
				flag=1;
			}
		}
	}
	if(flag==0){
		cout<<0;
		cout<<0;
		return 0;
	}
	flag=0;
	if(zw1[2]=='A'){
		if(zw2[2]=='B'){
			cout<<1;
			return 0;
		} 
	} 
	if(zw1[2]=='B'){
		if(zw2[2]=='A'||zw2[2]=='C'){
			cout<<1;
			return 0;
		} 
	} 
	if(zw1[2]=='C'){
		if(zw2[2]=='B'){
			cout<<1;
			return 0;
		} 
	}
	if(zw1[2]=='D'){
		if(zw2[2]=='F'){
			cout<<1;
			return 0;
		} 
	}
	if(zw1[2]=='F'){
		if(zw2[2]=='D'){
			cout<<1;
			return 0;
		} 
	}
	cout<<0;
	return 0;
}
