#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h[4],e[4];
	int l,f;
	cin>>l>>h[3]>>f>>e[3];
	if(l==f){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(h[1]==e[1]&&h[2]==e[2]){
		cout<<"11";
	}else{
		cout<<"00";
	}
	if(h[3]=="A"&&e[3]=="B"||h[3]=="B"&&e[3]=="A"||h[3]=="B"&&e[3]=="C"||h[3]=="C"&&e[3]=="B"||h[3]=="D"&&e[3]=="F"||h[3]=="F"&&e[3]=="D"){
		cout<<"0";
	}else{
		cout<<"1";
	}
	return 0;
} 
