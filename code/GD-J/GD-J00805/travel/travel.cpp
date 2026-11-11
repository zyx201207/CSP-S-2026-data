#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16"||c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	int R,X;
	R=s1[0]*10+s1[1];
	X=s2[0]*10+s2[1];
	if(X==R){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
		
	}
	char y,z;
	y=s1[2];
	z=s2[2];
	if((y>='A'&&y<='C'&&z>='A'&&z<='C')||(y>='D'&&y<='F'&&z>='D'&&z<='F')){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(((char)(y+1)==z||(char)(y-1)==z)&&(y!='C'&&z!='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
} 
