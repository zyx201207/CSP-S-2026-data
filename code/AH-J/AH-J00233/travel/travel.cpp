#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
string x1,x2,Y1,y2;
bool solve(string x,string y){
	if((x=="D"&&y=="F")||(y=="D"&&x=="F"))return true;
	if((x=="A"&&y=="B")||(x=="A"&&y=="C"))return true;
	if((y=="A"&&x=="B")||(y=="A"&&x=="C"))return true;
	if((x=="B"&&y=="A")||(x=="B"&&y=="C"))return true;
	if((y=="B"&&x=="A")||(y=="B"&&x=="C"))return true;
	if((x=="C"&&y=="A")||(x=="C"&&y=="B"))return true;
	if((y=="C"&&x=="A")||(y=="C"&&x=="B"))return true;
	return false;
}
bool check(string x,string y){
	if((x=="D"&&y=="F")||(x=="F"&&y=="D"))return true;
	if((x=="C"&&y=="B")||(x=="B"&&y=="C"))return true;
	if((x=="B"&&y=="A")||(x=="A"&&y=="B"))return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=s1[0]+s1[1];
	x2=s2[0]+s2[1];
	Y1=s1[2];
	y2=s2[2];
	string s;
	if(c1==c2){
		s+='1';
		if(x1==x2){
			s+='1';
			if(x1==x2&&solve(Y1,y2)){
				s+='1';
				if(check(Y1,y2))s+='1';
				else s+='0';
			}else s+="00";
		}else s+="000";
	}else s+="0000";
	cout<<s;
	return 0;
}
