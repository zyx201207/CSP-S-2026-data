#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[5];
int main(){
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		a[1]=1;
		string cp=c2[0],sp=s2[0];
		cp+=c2[1];
		sp+=s2[1];
		if(cp==sp) a[2]=1;
		if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C') c2[2]='1';
		else c2[2]='2';
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') s2[2]='1';
		else s2[2]='2';
		if(s2[2]==c2[2]) a[3]=1;
		if((a[2]==1&&a[3]==1)&&(c2[2]+1==s2[2]&&c2[2]-1==s2[2])) a[4]=1;
	}
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
} 
