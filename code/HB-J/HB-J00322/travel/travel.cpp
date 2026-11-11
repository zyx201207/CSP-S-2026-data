#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1[1]==s1[1]&&c1[2]==s1[2]){
		if(c2[1]==s2[1]&&c2[2]==s2[2]){
			if((c2[3]=='A'&&s2[3]=='B')||(c2[3]=='A'&&s2[3]=='C')||(c2[3]=='B'&&s2[3]=='A')||(c2[3]=='B'&&s2[3]=='C')||(c2[3]=='C'&&s2[3]=='A')||(c2[3]=='C'&&s2[3]=='B')||(c2[3]=='D'&&s2[3]=='F')||(c2[3]=='F'&&s2[3]=='D')){
				if((c2[3]=='A'&&s2[3]=='B')||(c2[3]=='B'&&s2[3]=='A')||(c2[3]=='B'&&s2[3]=='C')||(c2[3]=='C'&&s2[3]=='B')||(c2[3]=='D'&&s2[3]=='F')||(c2[3]=='F'&&s2[3]=='D')){
					cout<<1111;
				}
				else{
					cout<<1110;
				}	
			}
			else{
				cout<<1100;
			}		
		}
		else{
			cout<<1000;
		}
	}
	else{
		cout<<0000;
	}
	return 0;
}
