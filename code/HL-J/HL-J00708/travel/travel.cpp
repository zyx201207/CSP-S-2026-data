#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,c;
	string b,d;
	bool e=false,f=false,g=false;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		f=true;
	}else{
		cout<<"0";
	}
	if((b[0]==d[0]&&b[1]==d[1])&&f==true){
		cout<<"1";
		g=true;
	}else{
		cout<<"0";
	}
	if(((b[2]<=67&&d[2]<=67)||(b[2]>67&&d[2]>67))&&g==true){
		cout<<"1";
		e=true;
	}else{
		cout<<"0";
	}
	if((b[2]+1==d[2]||d[2]+1==b[2])&&e==true){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	
	
	
	
	
	return 0;
}