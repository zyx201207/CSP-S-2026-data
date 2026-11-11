#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>> s1 >> s2;
	cin>> s3 >> s4;
	int flag1=0,flag2=0,flag3=0,flag4=0;
	if(s1[0]==s3[0] && s1[1]==s3[1]) flag1=1;
	if(flag1==1){
		if(s2[0]==s4[0] && s2[1]==s4[1]) flag2=1;
	}
	if(flag2==1){
		if(s2[2]=='A' && s4[2]=='B') flag3=1;
		else if(s2[2]=='A' && s4[2]=='C') flag3=1;
		else if(s2[2]=='B' && s4[2]=='C') flag3=1;
		else if(s2[2]=='B' && s4[2]=='A') flag3=1;
		else if(s2[2]=='C' && s4[2]=='A') flag3=1;
		else if(s2[2]=='C' && s4[2]=='B') flag3=1;
		else if(s2[2]=='F' && s4[2]=='D') flag3=1;
		else if(s2[2]=='D' && s4[2]=='F') flag3=1;
	}
	if(flag3==1){
		if(s2[2]=='A' && s4[2]=='B') flag4=1;
		if(s2[2]=='B' && s4[2]=='C') flag4=1;
		if(s2[2]=='B' && s4[2]=='A') flag4=1;
		if(s2[2]=='C' && s4[2]=='B') flag4=1;
		if(s2[2]=='F' && s4[2]=='D') flag4=1;
		if(s2[2]=='D' && s4[2]=='F') flag4=1;
	}
//	cout<< s1 << endl;
//	cout<< s2 << endl;
//	cout<< s3 << endl;
//	cout<< s4 << endl;
    cout<< flag1 << flag2 << flag3 << flag4;
	return 0;
}
