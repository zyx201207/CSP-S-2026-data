#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	string temp1 = "", temp2 = "";
	temp1 += s1[0] + s1[1];
	temp2 += s2[0] + s2[1];
	if(c1 == c2 && temp1 == temp2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1 == c2 
	&& temp1 == temp2 
	&& ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') 
	|| (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))
	){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(c1 == c2 
	&& temp1 == temp2 
	&& ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C' && abs(s1[2] - s2[2]) == 1) 
	|| (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))
	){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	
	return 0;
}