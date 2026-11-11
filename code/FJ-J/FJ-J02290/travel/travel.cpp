#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string sz1=""+s1[0],sz2=""+s2[0];
	sz1=sz1+s1[1],sz2=sz2+s2[1];
	string ans="";
	if(c1==c2){
		ans=ans+'1';
	}
	else{
		ans=ans+'0';
	}
	if(c1==c2&&sz1==sz2){
		ans=ans+'1';
	}
	else{
		ans=ans+'0';
	}
	if(c1==c2&&sz1==sz2&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))){
		ans=ans+'1';
	}
	else{
		ans=ans+'0';
	}
	if(c1==c2&&sz1==sz2&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))&&((abs(s1[2]-s2[2])==1)||(abs(s1[2]-s2[2])==2&&(s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')))){
		ans=ans+'1';
	}
	else{
		ans=ans+'0';
	}
	cout << ans;
	
	return 0;
}
