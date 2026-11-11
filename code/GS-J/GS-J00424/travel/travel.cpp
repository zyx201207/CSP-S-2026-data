#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a1;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1 = "1";
	}else{
		a1 = "0000";
		cout<<a1;
		return 0;
	}
	if(s1[0]==s2[0]&&s2[1] == s1[1]){
		a1 = "11";
	}
	else{
		a1 = "1000";
		cout<<a1;
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='D'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='C'&&s2[2]=='E'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='A'&&s2[2]=='D'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='A'&&s2[2]=='E'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='B'&&s2[2]=='D'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='B'&&s2[2]=='E'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='D'&&s2[2]=='A'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='E'&&s2[2]=='A'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='D'&&s2[2]=='B'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='E'&&s2[2]=='B'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='E'&&s2[2]=='C'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}else if(s1[2]=='D'&&s2[2]=='C'){
		a1 = "1100";
		cout<<a1;
		return 0;	
	}
	else if(s1[2] == 'A'||'B'||'C' && s2[2] == 'A'||'B'||'C' ^ s1[2]=='D'||'E' && s2[2]=='D'||'E')
		a1 = "111";
	else{
		a1 = "1100";
		cout<<a1;
		return 0;
	}
	if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2] || s2[2] - 1 == s1[2] || s2[2] + 1 == s1[2])
		a1 = "1111";
	else{
		a1 = "1110";
		cout<<a1;
		return 0;
	}
	cout<<a1;
	return 0;
 
} 
