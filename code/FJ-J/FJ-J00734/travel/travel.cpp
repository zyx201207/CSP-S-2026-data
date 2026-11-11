#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	string ro1=s1.substr(0,2);
	string ro2=s2.substr(0,2);
	if(ro1!=ro2){
		cout<<"000";
		return 0;
	} 
	cout<<1;
	char si1=s1[2],si2=s2[2];
	if(si1=='A'){
		if(si2=='B') cout<<"11";
		else if(si2=='C') cout<<"10";
		else cout<<"00";
	}
	else if(si1=='B'){
		if(si2=='A'||si2=='C') cout<<"11";
		else cout<<"00";
	}
	else if(si1=='C'){
		if(si2=='B') cout<<"11";
		else if(si2=='A') cout<<"10";
		else cout<<"00";
	}
	else if(si1=='D'){
		if(si2=='F') cout<<"11";
		else cout<<"00";
	}
	else if(si1=='F'){
		if(si2=='D') cout<<"11";
		else cout<<"00";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
