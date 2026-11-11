#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	int a1,a2,a3,a4;
	cin>>c1>>c2>>c3>>c4;
	
	if(c1==c3){
		a1=1;
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			a2=1;
			if((c2[2]<='C'&&c4[2]<='C')||(c2[2]>='D'&&c4[2]>='D')){
				a3=1;
				if(abs(c2[2]-c4[2])<=1&&(c2[2]!='C'&&c4[2]!='D')) a4=1;
				else a4=0;
				if((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'||c4[2]=='F')) a4=1;
			}
			else{
				a3=0;
				a4=0;
			}
			
		}
		else{
			a2=0;
			a3=0;
			a4=0;
		}
		
	}
	else{
		a1=0;
		a2=0;
		a3=0;
		a4=0;
	}
	
	
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
