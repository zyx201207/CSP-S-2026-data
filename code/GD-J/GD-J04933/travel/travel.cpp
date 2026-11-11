#include <bits/stdc++.h>
using namespare std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(b.(0)==c.(0)&&b.(1)==c.(1)){
		cout<<"1";
		if((b>"01D"&&d>"01D")||((b>"01A"&&b<"18C")&&(d>"01A"&&d<"18C")){
			cout<<"1";
		}
		if((b-d)==1||(b-d)==-1){
			cout<<"1";
		}
	}
	else{
		cout<<"0"<<"0";
	}
	
	return 0;
}

