#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string so,se;
	cin>>a>>so>>b>>se;
	bool f=1;
	for(int i=0;i<2;i++){
		if(so[i]!=se[i]) f=0;
	}
	if(a==b){ //1
		cout<<1;
		if(f) cout<<1; //2
		else cout<<0<<0<<0;
		
		char o=so[2],e=se[2];
		if(f){ //3
			if((o=='C'||o=='D')&&(e=='C'||e=='D')) cout<<0;
			else{
				if((o=='B'||o=='A')&&(e=='B'||e=='A')) cout<<1;
				else if((o=='F'||o=='D')&&(e=='F'||e=='D')) cout<<1;
				else if((o=='C'||o=='A')&&(e=='C'||e=='A')) cout<<1;
				else if((o=='C'||o=='B')&&(e=='C'||e=='B')) cout<<1;
				else cout<<0;
			}
		}
		
		o=so[2];
		e=se[2];
		if(f){ //4
			if((o=='C'||o=='D')&&(e=='C'||e=='D')) cout<<0;
			else{
				if((o=='B'||o=='A')&&(e=='B'||e=='A')) cout<<1;
				else if((o=='F'||o=='D')&&(e=='F'||e=='D')) cout<<1;
				else if((o=='C'||o=='B')&&(e=='C'||e=='B')) cout<<1;
				else cout<<0;
			}
		}
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
