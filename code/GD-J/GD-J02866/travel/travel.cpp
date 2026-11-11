#include<bits/stdc++.h> 
using namespace std;
string id1,id2,s1,s2;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>id1>>s1>>id2>>s2;
	if(id1==id2){
		printf("1");
		f=1;
	}
	else printf("0");
	if(f&&s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");	
	else{
		printf("0");
		f=0;	
	}
	if(f&&(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')))) printf("1");
	else{
		printf("0");
		f=0;	
	}
	if(f&&abs(s1[2]-s2[2])==1) printf("1");
	else printf("0");
	return 0;
}
