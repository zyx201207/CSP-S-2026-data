#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,a="",b="";
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}

	a=c1[0]+c1[1];
	b=c2[0]+c2[1];

	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}

	a=s1[2];
	b=s2[2];

	if(a=="A"&&(b=="B"||b=="C")){
		cout<<1;
	}
	else if(a=="B"&&(b=="A"||b=="C")){
		cout<<1;
	}
	else if(a=="C"&&(b=="A"||b=="B")){
		cout<<1;
	}
	else if(a=="D"&&b=="F"){
		cout<<1;
	}
	else if(a=="F"&&b=="D"){
		cout<<1;
	}
	else {
		cout<<0;
	}


	if(a=="A"&&b=="B"){
		cout<<1;
	}
	else if(a=="B"&&(b=="C"||b=="A")){
		cout<<1;
	}
	else if(a=="C"&&b=="B"){
		cout<<1;
	}
	else if(a=="D"&&b=="F"){
		cout<<1;
	}
	else if(a=="F"&&b=="D"){
		cout<<1;
	}
	else {
		cout<<0;
	}
    return 0;
}
