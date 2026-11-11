#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+=49;
		string a1,a2,b1,b2;
		for(int i=0; i<2; i++){
			a1+=s1[i];
			a2+=s2[i];
		}
		b1=s1[2];
		b2=s2[2];
		if(a1==a2){
			s+=49;
			if(b1<="C"&&b1>="A"){
				if(b2<="C"&&b2>="A"){
					s+=49;
					if(b1=="B"||b2=="B"){
						s+=49;
					}
					else{
						s+=48;
					}
				}
				else{
					for(int i=0; i<2; i++) s+=48;
				}
			}
			else if(b1=="D"||b1=="F"){
				if(b2=="D"||b2=="F"){
					s+=49;
					s+=49;
				}	
				else{
					for(int i=0; i<2; i++) s+=48;	
				}
			}
		}
		else{
			for(int i=0; i<3; i++) s+=48;	
		}
	}else{
		for(int i=0; i<4; i++) s+=48;
	}
	cout<<s;
	return 0;
} 
