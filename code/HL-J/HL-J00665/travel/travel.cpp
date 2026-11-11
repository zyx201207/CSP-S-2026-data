#include<iostream>
#include<cmath>
using namespace std;
string xc,yc,xz,yz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xc>>xz>>yc>>yz;
	if(xc==yc){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}

	int p1=xz[0]-48,p2=yz[0]-48,z1=xz[1]-48,z2=yz[1]-48;
	if(p1==p2&&z1==z2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}

	char a=xz[2],b=yz[2];
	if(a>='A'&&a<='C'){
		if(b>='A'&&b<='C'){
			cout<<"1";
		}
		else if(b=='D'||b=='F'){
			cout<<"00";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			cout<<"1";
		}
		else if(b>='A'&&b<='C'){
			cout<<"00";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}

	int x=a-48,y=b-48;
	if(abs(x-y)==1||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
