//GZ-J00591 六盘水市第二十四中学 王胤杰 
#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){cout<<"1";}
	else{
		cout<<"0000";
		return 0;
	}
	if(sr[0]==sx[0]&&sr[1]==sx[1]){cout<<"1";}
	else{
		cout<<"000";
		return 0;
	}
	if(sr[2]=='A'||sr[2]=='C'){
		if(sx[2]=='B'){cout<<"11";}
		else if(sx[2]=='C'||sx[2]=='A'){cout<<"10";}
		else{cout<<"00";}
	}else if(sr[2]=='B'){
		if(sx[2]=='C'||sx[2]=='A'){cout<<"11";}
		else{cout<<"00";}
	}else{
		if(sx[3]=='A'||sx[3]=='B'||sx[3]=='C'){cout<<"10";}
		else{cout<<"11";}
	}
	return 0;
}
