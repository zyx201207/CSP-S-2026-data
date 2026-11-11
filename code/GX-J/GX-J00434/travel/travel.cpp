#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char x1,x2;
	cin>>a1>>a2>>x1;
	cin>>b1>>b2>>x2;
	if(a1 == b1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a2 == b2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(x1 == 'D'){
		if(x2 == 'F'){
			cout<<"11";
			return 0;
		}
	}else if(x1 == 'F'){
		if(x2 == 'D'){
			cout<<"11";
			return 0;
		}
	}
	if(x1 == 'A'){
		if(x2 == 'B' ||x2 == 'C'){
			if(x2 == 'B')cout<<"11";
			else cout<<"10";
			return 0;
		};
	}else if(x1 == 'B'){
		if(x2 == 'A' ||x2 == 'C'){
			cout<<"11";
			return 0;
		}
	}else if(x1 == 'C'){
		if(x2 == 'A' ||x2 == 'B'){
			if(x2 == 'B')cout<<"11";
			else cout<<"10";
			return 0;
		}
	}
	cout<<"00";
	return 0;
}
