#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int x1,x2,z1,z2 ;
char d1,d2;
bool vis[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		int num1=0,num2=0;
		if(i==0){
			num1+=c1[i]-'0';
			num2+=c2[i]-'0';
			x1+=num1*10;
			x2+=num2*10;
		}
		if(i==1){
			x1+=c1[i]-'0';
			x2+=c2[i]-'0';
		}
	}
	if(x1==x2) {
		vis[0]=1;	
	}
	else{
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<2;i++){
		int num1=0,num2=0;
		if(i==0){
			num1+=s1[i]-'0';
			num2+=s2[i]-'0';
			z1+=num1*10;
			z2+=num2*10;
		}
		if(i==1){
			z1+=s1[i]-'0';
			z2+=s2[i]-'0';
		}
	}
	if(z1==z2) vis[1]=1;
	else{
		cout<<"1000";
		return 0;	
	}
	if(s1[2]!=s2[2]){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				vis[2]=1;
			}
		}
		if(s1[2]=='D'||s1[2]=='F'){
			if(s2[2]=='D'||s2[2]=='F'){
				vis[2]=0;vis[3]=0;
			}
		}
	} 
	if(s1[2]!=s2[2]){
		if(s1[2]=='A'&&s2[2]=='B'){
			vis[3]=1;
		}
		else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
			vis[3]=1;
		}
		else if(s1[2]=='C'&&s2[2]=='B'){
			vis[3]=1;
		}
	}
	for(int i=0;i<4;i++){
		cout<<vis[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
