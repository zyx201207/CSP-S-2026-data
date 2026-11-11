#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	string c1,z1,c2,z2;
	char a,b,x,y;
	cin>>c1>>z1>>c2>>z2;
	
	a=z1[0],b=z1[1];
	x=z2[0],y=z2[1];
	
	if(c1==c2){
	cout<<1;
	char zm1=z1[2],zm2=z2[2];	
	if(a==x&&b==y){
		cout<<1;
		if((zm1<='C'&&zm2<='C')||(zm1>='D'&&zm2>='D')) cout<<1;
		else cout<<"00";
		if((zm1<='C'&&zm2<='C')||(zm1>='D'&&zm2>='D')){
			if(zm1-1==zm2||zm2-1==zm1) cout<<1;
			
			else cout<<"0";					
				}		

		}
		else{
			cout<<"000";
			return 0;	
		}		
	}

	else{
		cout<<"0000";
		return 0;
	}
	//02 01A 02 01B
	//02 01C 02 01A
	//02 01C 02 01D
	//02 02B 02 01A 
	//02 01A 03 01A 
}
