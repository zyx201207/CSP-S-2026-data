#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c3;
	bool n=true,c1h,c2h;//next high?
	string c2,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<"1";
	else {cout<<"0";n=false;}
	if((c2[0]==c4[0])&&(c2[1]==c4[1])&&n)cout<<"1";
	else {cout<<"0";n=false;}
	if((((c2[2]=='E'||c2[2]=='D')&&(c4[2]=='E'||c4[2]=='D'))||((c2[2]!='E'&&c2[2]!='D')&&(c4[2]!='E'&&c4[2]!='D')))&&n)cout<<"1";
	else {cout<<"0";n=false;}
	if((abs(int(c2[2]-c4[2]))==1)&&n)cout<<"1";
	else {cout<<"0";n=false;}
	return 0;
}
