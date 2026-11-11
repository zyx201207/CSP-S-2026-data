#include <bits/stdc++.h>
using namespace std;
string s1,s2,x1,x2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>s1>>s2>>x1>>x2;
	if(s1==x1) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s2[0]==x2[0]&&s2[1]==x2[1]){
		 cout<<1;
		 if((x2[2]=='F'||x2[2]=='D')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
         	cout<<0;
         	cout<<0;
		 }
		 else if((x2[2]=='A'||x2[2]=='B'||x2[2]=='C')&&(s2[2]=='F'||s2[2]=='D')){
		 	cout<<0;
		 	cout<<0;
		 }
		 else{
		 	cout<<1;
		 	if((s2[2]=='F'&&x2[2]=='D')||(s2[2]=='D'&&x2[2]=='F')) cout<<1;
			else if((s2[2]=='C'&&x2[2]=='B')||(s2[2]=='B'&&x2[2]=='A')) cout<<1;
			else if((x2[2]=='C'&&s2[2]=='B')||(x2[2]=='B'&&s2[2]=='A')) cout<<1;
			else cout<<0;
		 } 
	}
	else cout<<"000";
	
	return 0;
}

