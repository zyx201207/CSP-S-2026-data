#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	int y=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		y++;
		
	}
	else{
		cout<<0;
		//cout<<" a:    "<<1<<" ";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&y==1){
		cout<<1;
		y++;
		
	}
	else{
		cout<<0;
		//cout<<" b:    "<<1;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&y==2){
		cout<<1;
		y++;
		//cout<<" a:    "<<1;
	}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&y==2){
		cout<<1;
		y++;
		
	}
	else{
		cout<<0;
		//cout<<" c:    "<<1;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		if(y==3){
			cout<<1;
		//cout<<"y:  "<<y;
		y++;
		
		}
	}
	if(y!=4){
		//cout<<" d:    "<<1;
		cout<<0;
	}
	return 0;
}
