#include <bits/stdc++.h>
using namespace std;
string s1[4],s2[4];
int f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>s1[i]>>s2[i];
	}
	if(s1[1]==s1[2]){
		f1=1;
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(f1==1&&(s2[1][0]==s2[2][0]&&s2[1][1]==s2[2][1])){
		cout<<"1";
		f2=1;
	}else{
		cout<<"0";
	}
	if(f2==1&&(((s2[1][2]<='C'&&s2[1][2]>='A')&&(s2[2][2]<='C'&&s2[2][2]>='A'))||((s2[1][2]<='F'&&s2[1][2]>='D')&&(s2[2][2]<='F'&&s2[2][2]>='D')))){
		cout<<"1";
		f3=1;
	}else{
		cout<<"0";
	}
	if(f3==1&&(s2[1][2]+1==s2[2][2]||s2[1][2]-1==s2[2][2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
return 0;
}

