#include<bits/stdc++.h>
using namespace std;
int oj(string k){
	int n=0;
	for(int i=0;i<2;i++){
		n+=(n*10+k[i]-'0');
	}
	return n;
}
string st1,st2,st3,st4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>st1>>st2>>st3>>st4;
	if(st1==st3){
		cout<<"1";
		if(oj(st2)==oj(st4)){
			cout<<"1";
			if(st2[2]=='A'&&(st4[2]=='B'||st4[2]=='C')){
				cout<<1;
				if(st4[2]=='B')
					cout<<1;
				else cout<<0;
			}
			else if(st2[2]=='B'&&(st4[2]=='A'||st4[2]=='C')){
				cout<<"11";
			}
			else if(st2[2]=='C'&&(st4[2]=='B'||st4[2]=='A')){
				cout<<1;
				if(st4[2]=='B')
					cout<<1;
				else cout<<0;
			}
			else if(st2[2]=='E'&&st4[2]=='F')
				cout<<"11";
			else cout<<"00";
			
		}
		if(oj(st2)!=oj(st4))
			cout<<"000";
		
	}
	if(st1!=st3)cout<<"0000"; 
	
	return 0;
} 
