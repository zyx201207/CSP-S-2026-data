#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
void find(){
	if(a!=b){
		cout<<"0000";
		return;
	}
	if(a1[1]!=b1[1]||a1[0]!=b1[0]){
		cout<<"1000";
		return;
	}
	if(abs(int(a1[2]-b1[2]))==1){
		if(a1[2]=='C'&&b1[2]=='D'){
			cout<<"1100";
			return;
		}
		if(a1[2]=='D'&&b1[2]=='C'){
			cout<<"1100";
			return;
		}
		cout<<"1111";
		return;
	}
	if('D'==a1[2]||'E'==a1[2]){
		if('D'==b1[2]||'E'==b1[2]){
			cout<<"1110";
			return;
		}
		cout<<"1100";
		return;
	}
	if('D'==b1[2]||'E'==b1[2]){
			cout<<"1100";
			return;
		}
	cout<<"1110";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	find();
	return 0;
}
