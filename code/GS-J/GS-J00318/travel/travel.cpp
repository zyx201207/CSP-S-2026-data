#include<iostream>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rche,rwei,xche,xwei;
	cin>>rche;
	cin>>rwei;
	cin>>xche;
	cin>>xwei;
	string daan="0000";
	if(rche==xche){
		daan[0]='1';
		if((rwei[0]==xwei[0])&&(rwei[1]==xwei[1])){
			daan[1]='1';
			if(((rwei[2]>='A')&&(rwei[2]<='C')&&(xwei[2]>='A')&&(xwei[2]<='C'))||((rwei[2]>='D')&&(rwei[2]<='F')&&(xwei[2]>='D')&&(xwei[2]<='F'))){
				daan[2]='1';
				if((rwei[2]>='A')&&(rwei[2]<='C')&&(xwei[2]>='A')&&(xwei[2]<='C')){
					if((rwei[2]-xwei[2]==1)||(rwei[2]-xwei[2]==-1)){
						daan[3]='1';
					}
				}
				else{
					if((rwei[2]-xwei[2]==2)||(rwei[2]-xwei[2]==-2)){
						daan[3]='1';
					}
				}
			}
		}
	}
	cout<<daan<<endl;	
	return 0;
}
