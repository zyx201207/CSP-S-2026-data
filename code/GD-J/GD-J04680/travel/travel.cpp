#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	int x=b[0]*10+b[1];
	int y=d[0]*10+d[1];
	if(x!=y){
		cout<<"1000";
		return 0;
	}
	if(b[2]<='C'&&d[2]>='D'||b[2]>='D'&&d[2]<='C'){
		cout<<"1100";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
} 
