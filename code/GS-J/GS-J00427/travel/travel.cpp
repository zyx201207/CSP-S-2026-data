#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c1,z1,c2,z2;
	cin>>c1>>a>>z1>>c2>>b>>z2;
	if(c1 == c2){
		cout<<1;
	}else {
		cout<<"0000";
		return 0;
	}
	if(a == b){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(z1 == "A" && z2 == "B"){
		cout<<1;
	}else if(z1 == "D"&&z2 == "F"){
		cout<<1;
	}else if(z1 == "A"&&z2 == "C"){
		cout<<1;
	}else if(z1 == "B"&&z2 == "A"){
		cout<<1;
	}else if(z1 == "B"&&z2 == "C"){
		cout<<1;
	}else if(z1 == "C"&&z2 == "B"){
		cout<<1;
	}else if(z1 == "C"&&z2 == "A"){
		cout<<1;
	}else if(z1 == "F"&&z2 == "D"){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(z1 == "A"&&z2 == "B"){
		cout<<1;
	}else if(z1 == "D"&&z2 == "F"){
		cout<<1;
	}else if(z1 == "B"&&z2 == "C"){
		cout<<1;
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}
