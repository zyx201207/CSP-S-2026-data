#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string haoa,haob;
	char ans[100];
	cin>>a>>haoa>>b>>haob;
	
	if(a==b){
		ans[1]='1';
	}else{
		cout<<"0000";
		return 0;
	}
	if(haoa[1]==haob[1]){
		ans[2]='1';
	}else{
		cout<<"1000";
		return 0;
	}
	if(abs(haoa[2]-haob[2])==1&&(haoa[2]!='C'&&haob[2]!='D')&&(haoa[2]!='D'&&haob[2]!='C')){
		ans[3]='1';
		cout<<"1111";
		return 0;
	}else if(abs(haoa[2]-haob[2])<=2&&(haoa[2]!='C'||haob[2]!='F')&&(haoa[2]!='F'||haob[2]!='C')&&(haoa[2]!='C'||haob[2]!='D')&&(haoa[2]!='D'||haob[2]!='C')){
		cout<<"1110";
		return 0;
	}
	cout<<"1100";
	
	
	
	
	
	
	return 0;
	fclose(stdin);
	fclose(stdout);
	
} 
