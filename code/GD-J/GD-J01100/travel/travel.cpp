#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<1;
		
	} 
		else {
		cout<<'0000';
		return 0;
	}
	if(c[0]==c1[0]&&c[1]==c1[1]){
			cout<<1;
			
		}
			else {
			cout<<000;
			return 0;
			}
		if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(c1[2]=='A'||c1[2]=='B'||c1[2]=='C')){
				cout<<1;
		}
			
			else if((s[2]=='F'||s[2]=='D')&&(s1[2]=='F'||s1[2]=='D'))cout<<1;
			else {
			cout<<00;
			return 0; 
			}
		for(int i=3;i<=3;i++){
			if(s[i]=='A'&&s1[i]=='B')
				cout<<1;
			
			else if(s[i]=='B'&&s1[i]=='A')cout<<1;
			else if(s[i]=='B'&&s1[i]=='C')cout<<1;
			else if(s[i]=='C'&&s1[i]=='B')cout<<1;
			else if(s[i]=='D'&&s1[i]=='F')cout<<1;
			else if(s[i]=='F'&&s1[i]=='D')cout<<1;
			else cout<<0; 
		}
	return 0;
} 
