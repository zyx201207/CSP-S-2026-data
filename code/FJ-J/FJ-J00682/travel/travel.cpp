#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string str,str1,str2,str3;
	cin>>str>>str1>>str2>>str3;
	if(str == str2){
		cout<<1;
	}else{
		cout<<0;
	}
	if((str1[2] >= 'A' && str1[2] <= 'F' && str3[2] >= 'A' && str3[2] <= 'F') && str1[0] == str3[0] && str1[1] ==str3[1] && str1[2] != str3[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((str1[2] >= 'D' && str1[2] <= 'F') && (str3[2] >= 'D' && str3[2] <= 'F') || (str1[2] >= 'A' && str1[2] <= 'C') && (str3[2] >= 'A' && str3[2] <= 'C')) && str1[0] == str3[0] && str1[1] ==str3[1] && str1[2] != str3[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs(int(str1[2])-int(str3[2])) == 1 && (str1[2] != 'D' & str3[2] != 'C') && (str1[2] != 'C' && str3[2] != 'D') && str1[0] == str3[0] && str1[1] ==str3[1]){
		cout<<1;
	}else{
		cout<<0;
	}
} 
