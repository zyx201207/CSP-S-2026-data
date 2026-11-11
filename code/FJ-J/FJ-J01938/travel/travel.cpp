#include<bits/stdc++.h>
using namespace std;
string a;
string b;
string c;
string d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	} 
	if(b[1]!=d[1]||b[0]!=d[0]){
		cout<<"1000";
		return 0;
	}
	if((b[2]<='c'&&d[2]>='D')||(b[2]>='D'&&d[2]<='C')){
		cout<<"1100";
		return 0; 
	}
	if(abs(b[2]-d[2])==1){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
} 
