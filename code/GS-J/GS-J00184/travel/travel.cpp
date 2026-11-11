#include <bits/stdc++.h>
using namespace std;

int main(){
	string c_in[4+1]={};
	for(int i=1;i<=4;i++){
		cin>>c_in[i];
	}
	
	int c[2+1]={};
	char s[2+1]={};
	for(int i=1,j=1;i<=3;i+=2,j++){
		c[j]=(c_in[i][0]-'0')*10+(c_in[i][1]-'0');
		s[j]=(c_in[i+1][0]-'0')*10+(c_in[i+1][1]-'0');
		s[j+2]=(c_in[i+1][2]-'0'-16);
	}
	
	int r[4+1]={};
	if(c[1]==c[2]){
		r[1]=1;
		if(s[1]==s[2]){
			r[2]=1;
			if((1<=s[3]<=3 and 1<=s[4]<=3) or ((s[3]==4 or s[4]==6) and (s[3]==4 or s[4]==6))){
				r[3]=1;
				if(max(s[3],s[4])-min(s[3],s[4])==1) r[4]=1;
			}
		}
	}

	for(int i=1;i<=4;i++){
		cout<<r[i];
	}
	
	return 0;
}
