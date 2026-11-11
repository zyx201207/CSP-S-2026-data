#include<bits/stdc++.h>
using namespace std;
string jg[4];
int main(){
	
	string R1,R2,X1,X2;
	cin>>R1>>R2>>X1>>X2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(R1==X1) {
		jg[0]='1',jg[1]='0',jg[2]='0',jg[3]='0';
		if(R2[0]==X2[0]&&R2[1]==X2[1]){
			jg[1]='1',jg[2]='0',jg[3]='0';
			if((R2[2]-X2[2]<=3||X2[2]-R2[2]<=3)&&((R2[2]>='D'&&X2[2]>='D')||(R2[2]<='C'&&X2[2]<='C'))){
				jg[2]='1',jg[3]='0';
				if(R2[2]-X2[2]==1||X2[2]-R2[2]==1)
					{
						jg[3]='1';
						for(int i=0;i<4;i++)
							cout<<jg[i];
						return 0;
					}
				for(int i=0;i<4;i++)
					cout<<jg[i];
				return 0;
			} 
			for(int i=0;i<4;i++)
				cout<<jg[i];
			return 0;
		}
		for(int i=0;i<4;i++)
			cout<<jg[i];
		return 0;
	}
	else {
		jg[0]='0',jg[1]='0',jg[2]='0',jg[3]='0';
		cout<<jg[0]<<jg[1]<<jg[2]<<jg[3];
	}
	return 0;
}
