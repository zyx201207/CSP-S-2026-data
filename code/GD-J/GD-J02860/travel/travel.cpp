#include<bits/stdc++.h>
using namespace std;
#define t long long
int x1,c1,x2,c2;
char v1,v2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>x1>>x2>>v1>>c1>>c2>>v2;
	if (x1==c1){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}if (x2==c2){
		cout<<1;
	}else {
		cout<<"000";
		return 0;	
	}if (v1<='C'&&v2<='C'){
		cout<<1;
	}else if (v1>='D'&&v2>='D')cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if (abs(v1-v2)==1||(v1=='D'&&v2=='F')||(v2=='D'&&v1=='F'))cout<<1;
	else cout<<0;
	return 0;
} 
