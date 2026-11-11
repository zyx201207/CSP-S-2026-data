#include<bits/stdc++.h>
using namespace std;
string C1,S1,C2,S2;
int a,b,c,d;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>C1>>S1>>C2>>S2;
	if (C1==C2){
		a=1;
	}
	if (C1!=C2){
		a=0;
		b=0;
		c=0;
		d=0;
	}
	if(S1[0]==S2[0]&&S1[1]==S2[1]){
		b=1;
	}
	if(S1[0]!=S2[0]||S1[1]!=S2[1]){
		b=0;
	}
	if(C1!=C2){
		b=0;
	}
	if(C1==C2&&S1[0]==S2[0]&&S1[1]==S2[1]&&S1[2]-S2[2]==1){
		c=1;
	}
	if(C1==C2&&S1[0]==S2[0]&&S1[1]==S2[1]&&S1[2]-S2[2]==2){
		c=1;
	}
	if(S1[0]!=S2[0]||S1[1]!=S2[1]||S1[2]-S2[2]!=1&&S1[2]-S2[2]!=2){
		c=0;
	}
	if(C1!=C2){
		c=0;
    }
	if(S1[2]=='A'&&S2[2]=='B'){
		d=1;
	}
	if(S1[2]=='B'&&S2[2]=='C'){
		d=1;
	}
	if(S1[2]=='D'&&S2[2]=='F'){
		d=1;
	}
	if(S1[2]=='B'&&S2[2]=='A'){
		d=1;
	}
	if(S1[2]=='C'&&S2[2]=='B'){
		d=1;
	}
	if(S1[2]=='F'&&S2[2]=='D'){
		d=1;
	}
	else{
		d=0;
	}
	cout<<a<<b<<c<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
