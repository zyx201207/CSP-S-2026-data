#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string p1,p2;
		char z1,z2;
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0' && s1[i]<='9') p1+=s1[i];
			else if(s1[i]>='A' && s1[i]<='F') z1=s1[i];
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0' && s2[i]<='9') p2+=s2[i];
			else if(s2[i]>='A' && s2[i]<='F') z2=s2[i];
		}
		if(p1==p2){
			cout<<"1";
			if((z1=='A' && z2=='B') ||
			   (z1=='B' && z2=='A') ||
			   (z1=='A' && z2=='C') ||
			   (z1=='C' && z2=='A') ||
			   (z1=='B' && z2=='C') ||
			   (z1=='C' && z2=='B') ||
			   (z1=='D' && z2=='F') ||
			   (z1=='F' && z2=='D') ){
			   		cout<<"1";
			   		if((z1=='A' && z2=='B') ||
			   			(z1=='B' && z2=='A') ||
			   			(z1=='B' && z2=='C') ||
			   			(z1=='C' && z2=='B') ||
			   			(z1=='D' && z2=='F') ||
			   			(z1=='F' && z2=='D') ){
			   				cout<<"1";
						}else{
							cout<<"0";
						}
			   }else{
			   		cout<<"00";
			   }
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
