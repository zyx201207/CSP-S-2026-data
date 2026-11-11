#include <bits/stdc++.h>
using namespace std;

string a1,b1,a2,b2;
string k;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1!=a2){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(a1[i]!=a2[i]){
			k+='0';
			break;
		}
		if(i==a1.size()-1) k+='1';
	}
	int b3=(b1[0]-'0')*10+(b1[1]-'0'),b4=(b2[0]-'0')*10+(b2[1]-'0');
	int x=(int)b1[2],y=(int)b2[2];
	if(b3==b4){
		k+='1';
		if(x+2==y && b1[2]=='D' || y+2==x && b2[2]=='D' || x+2==y && b1[2]=='A' || x+1==y && b1[2]=='B' || y+2==x && b2[2]=='A' || y+1==x && b2[2]=='B' || x+1==y && b1[2]=='A' || y+1==x && b2[2]=='A') k+='1';
		else k+='0';
	}
	else k+="00";
	if(b1[2]=='A' && b2[2]=='F' || b1[2]=='F' && b2[2]=='A' ||b1[2]=='C' && b2[2]=='D' || b1[2]=='D' && b2[2]=='C') k+='0';
	else{
		if(b3==b4 && b1[2]=='F' && b2[2]=='D' || b3==b4 && b1[2]=='D' && b2[2]=='F' || b3-1==b4 && b1[2]==b2[2] || b4-1==b3 && b1[2]==b2[2] || b1[2]+1==b2[2] && b3==b4 || b1[2]-1==b2[2] && b3==b4) k+='1';
		else k+='0';
	}
	for(int i=0;i<k.size();i++) cout<<k[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
