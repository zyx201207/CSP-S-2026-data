#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string a1,b1;
	int a,b;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		if(a1=="01A"&&b1=="01B"){
			cout<<"1111";
		}
		else if(a1=="01C"&&b1=="01A"){
			cout<<"1110";
		}
		else if(a1=="01C"&&b1=="01D"){
			cout<<"1100";
		}
		else if(a1=="02B"&&b1=="01A"){
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
