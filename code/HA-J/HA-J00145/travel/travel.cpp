#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[1]==d[1]&&b[0]==d[0]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs((b[2]-'A')-(d[2]-'A'))==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
