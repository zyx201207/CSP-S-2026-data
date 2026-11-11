//贵阳第三中学 刘谌桦 GZ-J00300 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	feropen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else {
		cout<<"0000";
		return  0;
	}
	char ca=s1[0];
	char cb=s1[1];
	char sa=s2[0];
	char sn=s2[1];
	if(c1==c2&&ca==sa&&cb==sn){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	char cc=s1[2];
	char sc=s2[2];
	if(c1==c2&&ca==sa&&cb==sn&&cc>='A'&&cc<='C'&&sc>='A'&&sc<='C'||cc>='D'&&cc<='F'&&sc>='D'&&sc<='F'){
		cout<<"1"; 
	}else {
		cout<<"00";
		return 0;
	}
	if(ca==sa&&cb==sn&&cc=='A'&&sc=='B'||cc=='B'&&sc=='A'||cc=='B'&&sc=='C'||cc=='C'&&sc=='B'||cc=='F'&&sc=='D'||cc=='D'&&sc=='F'){
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	return 0; 
}
