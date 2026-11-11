#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c_1,s_1,c_2,s_2;
	cin>>c_1>>s_1>>c_2>>s_2;
	
	bool x=0,p=0,c=0,l=0;
	
	string ps_1,ps_2;
	
	char st_1=s_1[2],st_2=s_2[2];
	
	for(int i=0;i<=1;i++){
		ps_1+=s_1[i];
		ps_2+=s_2[i];
	}
	
	if(c_1==c_2){
		x=1;
		if(ps_1==ps_2){
		p=1;
		if(((st_1=='A'||st_1=='B'||st_1=='C')&&(st_2=='A'||st_2=='B'||st_2=='C'))||((st_1=='D'||st_1=='F')&&(st_2=='D'||st_2=='F'))){
		c=1;
		if((int)st_1-st_2==1||(int)st_2-st_1==1){
			l=1;
		}
	}
	}
	}
	
	
	cout<<x<<p<<c<<l<<'\n';
	return 0;
}
