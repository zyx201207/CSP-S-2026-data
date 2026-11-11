//GZ-J00359 观山湖区铭苑中学 常淋淇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen;{"travel.in","r",stdin;}
	freopen;{"travel.out","w",stdout;}
	int rc,xc;
	string rz,xz,s="";
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc){
		s+="1";
		if(rz[0]==xz[0] && rz[1]==xz[1]){
			s+="1";
			if(rz[2]<='c' && xz[2]<='c'){
				s+="1";
				if(rz[2]-1==xz[2] || xz[2]-1==rz[2]) s+="1";
				else s+="0";
			}
			else if(rz[2]>'c' && xz[2]>'c') s+="11";
			else s+="00";
		}
		else s+="000";
	}
	else s+="0000";
	cout<<s;
	return 0;	
}
