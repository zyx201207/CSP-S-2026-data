#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;

	if(a!=b){
		cout<<"0000";
		return 0;
	}
	if(c[0]!=d[0]||c[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	if(c[2]=='F'&&d[2]=='D'){
		cout<<"1111";
		return 0;
	}else if(c[2]=='D'&&d[2]=='F'){
		cout<<"1111";
		return 0;
	}else if(c[2]=='A'&&d[2]=='B'){
		cout<<"1111";
		return 0;
	}else if(c[2]=='B'&&d[2]=='A'){
		cout<<"1111";
		return 0;		
	}else if(c[2]=='B'&&d[2]=='C'){
		cout<<"1111";
		return 0;		
	}else if(c[2]=='C'&&d[2]=='B'){
		cout<<"1111";
		return 0;		
	}else if(c[2]=='A'&&d[2]=='C'){
		cout<<"1110";
		return 0;
	}else if(c[2]=='C'&&d[2]=='A'){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1100";
		return 0;
	}
	
	return 0;
}
