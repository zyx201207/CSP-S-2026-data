#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2,z1="",z2="",w1="",w2="",daan="";
	cin>>c1>>s1>>c2>>s2;
	z1+=s1[0];
	z1+=s1[1];
	z2+=s2[0];
	z2+=s2[1];
	w1=s1[2];
	w2=s2[2];
	if(c1==c2){
		daan+="1";
		if(z1==z2){
			daan+="1";
			if((w1=="F"&&w2=="D")||(w1=="D"&&w2=="F")){
				daan+="11";
			}else if((w1=="A"&&w2=="B")||(w1=="B"&&w2=="C")||(w2=="A"&&w1=="B")||(w2=="B"&&w1=="C")){
				daan+="11";
			}else if((w1=="A"&&w2=="C")||(w2=="A"&&w1=="C")){
				daan+="10";
			}else{
				daan+="00";
			}
		}else{
			daan+="000";
		}
	}else{
		daan="0000";
	}
	cout<<daan;
	return 0;
}
