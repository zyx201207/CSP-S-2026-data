#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 	string c1,c2,s1,s2;
 	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		string c21,s21;
		for(int i=0;i<=1;i++){
			c21+=c2[i];
		}
		for(int i=0;i<=1;i++){
			s21+=s2[i];
		}
		if(c21==s21){
			cout<<1;
			if(s2[2]<='C'&&c2[2]<='C'&&s2[2]>='A'&&c2[2]>='A'){
				cout<<1;
				if(abs(s2[2]-c2[2])==1) cout<<1;
				else cout<<0;
			}
			if((s2[2]=='D'&&c2[2]=='F')||(s2[2]=='F'&&c2[2]=='D')){
				cout<<11;
			}
			else{
				cout<<"00";
			}
		} 
		else{
			cout<<"000";
			return 0;
		} 
		
	} 
	else{
		cout<<"0000";
		return 0;
	} 
		
}