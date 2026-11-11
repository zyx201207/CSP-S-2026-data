#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string pai1,pai2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;i++){
			pai1+=s1[i];
			pai2+=s2[i];
		}
		if(pai1==pai2){
			cout<<1;
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
				cout<<1;
				if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
					if(s1[2]==char(s2[2]-1)||s1[2]==char(s2[2]+1)){
						cout<<1;
					}
					else{
						cout<<0;
					}	
				}
				if((s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
					cout<<1;	
				}else{
					cout<<0;
				}
				
			}
			else{
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
	
	
	
	
	return 0;
}
