#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool h=0,z=0,a=0,x=0;
	int c1, c2;
	cin>>c1;
	char s1[3],s2[3];
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		h=1;
	}
	cout<<h;
	if(h==1){
		if(s1[0]-'0'==s2[0]-'0'){
		if(s1[1]-'0'==s2[1]-'0'){
			z=1;
			if(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F'){
				a=1;
	}
		}
	}
	}
	cout<<z;
	cout<<a;
	if(a==1){
		if((s1[2]-'A')-(s2[2]-'A')==1||(s1[2]-'A')-(s2[2]-'A')==-1){
		x=1;
		if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C')
		x=0;
	}
	else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
		x=1;
	}
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

