#include<bits/stdc++.h>
using namespace std;
	string c1,s1,c2,s2,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) d+="1";
	else d+="0";
	if(d[0]=='0') {
		d+="000";
	}
	else if(d[0]=='1') {
	
	if(s1[0]==s2[0] and s1[1]==s2[1]) d+="1";
	else d+="0";
	if(d[1]=='0') d+="0";
	else{
		if(s1[2]=='A' and s2[2]=='B' or s2[2]=='C') d+="1";
		else if(s1[2]=='B' and s2[2]=='A' or s2[2]=='C') d+="1";
		else if(s1[2]=='C' and s2[2]=='B' or s2[2]=='A') d+="1";
		else if(s1[2]=='D' and s2[2]=='F') d+="1";
		else if(s1[2]=='F' and s2[2]=='D') d+="1";
		else d+='0';
	}
	if(d[2]=='0') d+="0";
	else{
		if(s1[2]=='A' and s2[2]=='B') d+="1";
		else if(s1[2]=='B' and s2[2]=='A' or s2[2]=='C') d+="1";
		else if(s1[2]=='C' and s2[2]=='B') d+="1";
		else if(s1[2]=='D' and s2[2]=='F') d+="1";
		else if(s1[2]=='F' and s2[2]=='D') d+="1";
		else d+='0';
	}
	
}
		cout<<d;
		return 0;
} 
