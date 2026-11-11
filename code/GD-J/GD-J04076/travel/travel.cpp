#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c=0,s=0;
	string q,a;
	cin >>c >>q >>s >>a;
	if(c==s){
		cout <<"1";
	}else{
		cout <<"0000";
		return 0;
	}
	
	
	if(q[1]==a[1]&&q[0]==a[0]){
		cout <<"1";
	}else{
		cout <<"000";
		return 0;
	}
	
	
	if(q[2]<='C'&&a[2]<='C'){
		cout <<"1";
		if(q[2]+1==a[2]||q[2]-1==a[2]){
			cout <<"1";
		}else{
			cout <<"0";
		}
	}
	else if(q[2]>='D'&&a[2]>='D'){
		cout <<"11";
	}
	else{
		cout <<"00";
	}
	return 0;
} 
