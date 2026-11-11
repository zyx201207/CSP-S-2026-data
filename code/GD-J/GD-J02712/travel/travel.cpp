#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	if(r2[0]!=x2[0]||r2[1]!=x2[1]){
		cout<<"1000";
		return 0;
	}
	if(r2[2]>='D'){
		if(x2[2]<='C'){
			cout<<"1100";
			return 0;
		}
	}
	else if(r2[2]<='C'){
		if(x2[2]>='D'){
			cout<<"1100";
			return 0;
		}
	}
	if(r2[2]-x2[2]==1||x2[2]-r2[2]==1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
