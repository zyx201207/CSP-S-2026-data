#include<bits/stdc++.h>
using namespace std;
string st1,st2,st3,st4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>st1>>st2>>st3>>st4;
	if(st1==st3){
		cout<<1;
		if(st2[1]==st4[1]&&st2[0]==st4[0]){
			cout<<1;
			if((st4[2]=='A'||st4[2]=='B'||st4[2]=='C')&&(st2[2]=='A'||st2[2]=='B'||st2[2]=='C')){
				cout<<1;
				if(st2[2]+1==st4[2]||st2[2]==st4[2]+1)cout<<1;
				else cout<<0;	
			}
			else if((st2[2]=='D'||st2[2]=='F')&&(st4[2]=='D'||st4[2]=='F'))cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	
	return 0;
}
