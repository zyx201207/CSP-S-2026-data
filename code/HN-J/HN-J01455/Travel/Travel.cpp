#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("Travel.in","r",stdin);
	freopen("Travel.out","w",stdout);
	int a,e,s,f;
	a=0;
	e=0;
	s=0;
	f=0;
	string b[19]={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18"};
	string z[5]={"A","B","C","D","F"};
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char c;
	c=s1[0]+s1[1];
	char d;
	d=s2[0]+s2[1];
	string h;
	h=s1[2];
	string g;
	g=s2[2];
	for(int i=0;i<=17;i++){
		if(i==1||i==15){
			a+=0;
			
		}
		else{
			if(b[i]==c1&&b[i]==c2){
				a+=1;
				
			}
		}

		
	}
	
	if(c==d){
		e++;
	}
	int q=0;
	int o=0;
	for(int j=0;j<5;j++){	
		if(z[j]==h){
			q+=j;
		}
		if(z[j]==g){
			o+=j;
		}}
		
	if(q<=2&&o<=2){
		s=1;
	}
		else{			
			if(q>=3&&o>=3){
				s=1;
			}}
	if(q+1==o||q-1==o){
		f=1;
	}
	
	

	cout<<a;
	cout<<e;	
	cout<<s;
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
