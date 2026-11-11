#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[10],c2[10],s1[10],s2[10];
	scanf("%s",c1+1);
	scanf("%s",s1+1);
	scanf("%s",c2+1);
	scanf("%s",s2+1);
	if(c1[1]==c2[1]&&c1[2]==c2[2]){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s1[3]=='B'&&(s2[3]=='A'||s2[3]=='C')){
		cout<<11;	
	}else if(s2[3]=='B'&&(s1[3]=='A'||s1[3]=='C')){
		cout<<11;	
	}else if((s2[3]=='A'||s2[3]=='C')&&(s1[3]=='A'||s1[3]=='C')){
		cout<<10;
	}else if((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')){
		cout<<11;
	}else{
		cout<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
