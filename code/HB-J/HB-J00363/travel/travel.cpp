#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int abs2(int x){
	if(x<=0) return -1*x;
	else return x;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		s+='1';
		string pai1="00",pai2="00";
		pai1[0]=s1[0],pai1[1]=s1[1],pai2[0]=s2[0],pai2[1]=s2[1];
		//~ cout<<'#'<<pai1<<' '<<pai2<<'\n';
		if(pai1==pai2){
			s+='1';
			char w1=s1[2],w2=s2[2];
			if((w1=='A'||w1=='B'||w1=='C')&&(w2=='A'||w2=='B'||w2=='C')){
				s+='1';
				if(abs2((int)w1-(int)w2)==1) s+='1';
				else s+='0';
			}
			else if((w1=='D'||w1=='F')&&(w2=='D'||w2=='F')){
				s+="11";
			}
			else s+="00";
		}
		else s+="000";
	}
	else s+="0000";
	cout<<s;
	return 0;
}
