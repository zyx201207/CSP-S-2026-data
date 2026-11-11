// Gz-JOO614 遵义市第四初级中学 李浩然  
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string a1,a2,c1,c2;
	cin>>a1>>c1>>a2>>c2;
	string z="ABC0DF";
	
	
	if(a1==a2){
		cout<<"1";
		string w1,w2;
		w1=c1[0]+c1[1];
		w2=c2[0]+c2[1];
		if(w1==w2){
			cout<<"1";
			if(((c1[2]!='F'&&c1[2]!='D')||c2[2]!='D'&&c2[2]!='F')||((c2[2]=='D'&&c1[2]=='F')||c2[2]=='F'&&c1[2]=='D')){
				cout<<"1";
			    if((c1[2]=='A'&&c2[2]=='B')||(c2[2]=='A'&&c1[2]=='B')||(c1[2]=='B'&&c2[2]=='C')||(c2[2]=='C'&&c1[2]=='B')||(c1[2]=='F'&&c2[2]=='D')||(c2[2]=='F'&&c1[2]=='D')){
			    	cout<<"1";
				}
				else{
					cout<<"0";
					
				}
			}	else{
				cout<<"00";
			
				}
		}
		else{
			cout<<"000";
		
		}
	}
	else{
		cout<<"0000";
	}
}
//02 01A 02 01B
