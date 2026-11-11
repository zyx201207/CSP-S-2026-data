#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,c2;
	char s1[10],s2[10];
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	bool chex=0,pai=0,ce=0,ling=0;
	if(s1[3]=='F'){
		s1[3]='E';
	}
	if(s2[3]=='F'){
		s2[3]='E';
	}
	if (c1==c2){
	    cout<<'1';
	    chex=1;
	}else{
		cout<<'0';
	}
	if(chex&&s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<1;
		pai=1;
	}else{
		cout<<0;
	}
	if('A'<=s1[3]<='C'&&'A'<=s2[3]<='C'){
		ce=1;
	}else if('D'<=s1[3]<='E'&&'D'<=s2[3]<='E'){
		ce=1;
	} 
	if(s1[3]=='C'&&s2[3]=='D'||s1[3]=='D'&&s2[3]=='C') ce=0;
	if(chex&&pai&&ce){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[3]-s2[3]==1||s1[3]-s2[3]==-1){
		ling=1;
	}
	if(chex&&pai&&ce&&ling){
		cout<<1;
	}else{
		cout<<0;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
