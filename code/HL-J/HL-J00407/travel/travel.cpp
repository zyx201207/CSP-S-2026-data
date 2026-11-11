#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	long long a,b;
	cin>>c1>>s1>>c2>>s2;
	a=0;
	int t=0;
	int g=0;
    int d=0;
	string c="";
	if(s1[2]=='A'){
		t++;
		d++;
	}
	if(s1[2]=='B'){
		t++;
	}
	if(s1[2]=='C'){
		d++;
		t++;
	}
	
	if(s2[2]=='A'){
		d++;
		t++;
	}
	if(s2[2]=='B'){
		t++;
	}
	if(s2[2]=='C'){
		d++;
		t++;
	}
	if(t==0){
		t=2;
		g=1;
	}
	if(c1==c2){
		c+="1 ";
		a+=1;
	}
	else{
		c+="0 ";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		c+="1 ";
		a++;
	}
	else{
		c+="0 ";
	}
	if(a>=2){
		if(t==2){
			c+="1 ";
			a++;
		}
		else{
			c+="0 ";
		}
	}
	else{
		c+="0 ";
	}
	if(a>=3){
		if(g==1){
			c+="1 ";
		}
		else{
			if(d==2){
				c+="0 ";
			}
			else{
				c+="1 ";
			}
		}
	}
	else{
		c+="0 ";
	}

	
	cout<<c;
	return 0;
}

