#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool xiang=0,pai=0,side=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>c1 >>s1 >>c2 >>s2;
	
	if(c1==c2){
		cout <<1;
		xiang=1;
	}else{
		cout <<0;//xiang
	}
	if(xiang==1 && s1[0]==s2[0] && s1[1]==s2[1]){
		cout <<1;
		pai=1;
	}else{
		cout <<0;//pai
	}
	if(pai==1 && (((s1[2]>='A'&& s1[2]<='C')&&(s2[2]>='A'&& s2[2]<='C')) || ((s1[2]>='D'&& s1[2]<='F')&&(s2[2]>='D'&& s2[2]<='F')))){
		cout <<1;
		side=1;
	}else{
		cout <<0;
	}
	if(side==1 && abs(s1[2]-s2[2])==1){
		cout <<1;
	}else{
		cout <<0;
	}
} 
