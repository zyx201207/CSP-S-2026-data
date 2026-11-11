#include<bits/stdc++.h>
using namespace std;
int main(){
//	frepon("travel.in",'r',stdin);
//	frepon("travel.out",'w',stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	if(s1[1]==s2[1] and s1[0]==s2[0]){
		cout<<"1";
	}else{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	if(((s1[2]=='A' or s1[2]=='B' or s1[2]=='C')and(s2[2]=='A' or s2[2]=='B' or s2[2]=='C'))or((s1[2]=='D' or s1[2]=='E')and(s2[2]=='D' or s2[2]=='E'))){
		cout<<"1";
	}else{
		cout<<"0"<<"0";
		return 0;
	}
	if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='B') or (s1[2]=='D' and s2[2]=='E') or (s1[2]=='E' and s2[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
//	fclose(stdin);
//	fclose(stdout);
} 
