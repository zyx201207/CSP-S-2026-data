#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,p,p1,t;
char l,l1;
bool f=0;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		t+='1';
		for(int i=0;i<=1;i++){
			p+=s1[i];
			p1+=s2[i];
		}
		l+=s1[2];
		l1+=s2[2];
		if(p==p1){
			t+='1';
		}
		else{
			t+="000";
			f=1;
		}
		if(f==0){
			if(l=='A'||l=='B'||l=='C'&&l1=='A'||l1=='B'||l1=='C'){
				t+='1';
			}
			else if(l=='D'||l=='F'&&l1=='D'||l1=='F'){
				t+='1';
			}
			else{
				t+="00";
				f=1;
			}
		}
		if(f==0){
			x=int(l);
			y=int(l1);
			if(abs(x-y)==1){
				t+='1';
			}
			else t+='0';
		}
	}
	else{
		t+="0000";
	}
	cout<<t;
	
	return 0;
} 
