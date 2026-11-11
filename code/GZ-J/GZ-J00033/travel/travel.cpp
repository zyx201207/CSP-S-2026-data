// GZ-J00033 ЇќзвеЈ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Rc,Rz,Xc,Xz;
	char Rzz,Xzz,c;
	cin>>Rc;
	c=getchar();
	c=getchar();
	Rz=(c-'0')*10;
	c=getchar();
	Rz+=c-'0';
	Rzz=getchar();
	c=getchar();
	cin>>Xc;
	if(Xc!=Rc){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
	}
	c=getchar();
	c=getchar();
	Xz=(c-'0')*10;
	c=getchar();
	Xz+=c-'0';
	if(Xz==Rz){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	Xzz=getchar();
	if((Rzz<='C'&&Xzz<='C')||(Rzz>'C'&&Xzz>'C')){
		cout<<"1"; 
		if(abs(Rzz-Xzz)==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"00";
		return 0;
	}
	//cout<<Rc<<" "<<Rz<<" "<<Rzz<<" "<<Xc<<" "<<Xz<<" "<<Xzz;
	return 0;
}
