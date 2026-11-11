#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++)
		cin>>s1[i];
	cin>>c2;
	for(int i=1;i<=3;i++)
		cin>>s2[i];
	if(c1!=c2){		
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1] && s1[2]==s2[2]){
		cout<<"11";
		
	}
	else{
		cout<<"1000";
		return 0;
	}
	if(s1[3]=='A' && s2[3]=='B'){
		cout<<"11";
		return 0;
	}
	else if(s1[3]=='A' && s2[3]=='C'){
		cout<<"10";
		return 0;
	}
	else if(s1[3]=='B' && s2[3]=='C'){
		cout<<"11";
		return 0;
	}
	else if(s1[3]=='B' && s2[3]=='A'){
		cout<<"11";
		return 0;
	}
	else if(s1[3]=='C' && s2[3]=='A'){
		cout<<"10";
		return 0;
	}
	else if(s1[3]=='C' && s2[3]=='B'){
		cout<<"11";
		return 0;
	}
	else if(s1[3]=='F' && s2[3]=='D'){
		cout<<"11";
		return 0;
	}
	else if(s1[3]=='D' && s2[3]=='F'){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
}
