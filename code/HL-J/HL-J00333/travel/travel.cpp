#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a;
	cin>>a;
	int b;
	cin>>b;
	char n;
	cin>>n;
	int c;
	cin>>c;
	int d;
	cin>>d;
	char m;
	cin>>m;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b==d){
		cout<<"1";
		
	}else{
		cout<<"000";
		return 0;
	}
	if(n<='C'&&m<='C'){
		cout<<"1"; 
	}else if(n>'C'&&m>'C'){
	    cout<<"1";
    }else{
		cout<<"00";
		return 0;
	}
	char q=1,p=1;
	
	if((n+q)==m||(n-p)==m){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
