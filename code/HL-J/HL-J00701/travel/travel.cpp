#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if((c1[0]==c3[0])&&(c1[1]==c3[1])){
		cout<<1;
 	if(c2[0]==c4[0]&&c2[1]==c4[1]){
 		cout<<1; 
 		if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
 			cout<<1;
 			if( ((c2[2]=='A'||c2[2]=='B')&&(c4[2]=='A'||c4[2]=='B')) || ((c2[2]=='C'||c2[2]=='B')&&(c4[2]=='C'||c4[2]=='B')))
 			cout<<1; else cout<<0;
		 }
		else{
		if((c2[2]=='F'||c2[2]=='D')&&(c4[2]=='F'||c4[2]=='D')){
 			cout<<1<<1<<1;
		}
		 else cout<<0<<0;
		}
		}
 		
	else cout<<0<<0<<0;
	}
	else{
	cout<<0<<0<<0<<0;
	return 0;
	}
return 0;
}