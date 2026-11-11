#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	string c1,c2;
	char s1[3]={};
	char s2[3]={};
	cin>>c1>>s1>>c2>>s2;
	char a[4]={};
	if(c1==c2){
		a[0]=1;
	}else{
		a[0]=0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		a[1]=1;
	}else{
		a[1]=0;
	}
	if(a[1]==1){
		if(s1[2]=='D' and s2[2]!='F'){
			a[2]=0;
		}
		else if(s2[2]=='D' and s1[2]!='F'){
			a[2]=0;
		}
		else{
			a[2]=1;
		}
	}else{
		a[2]=0;
	}
	if(a[2]==1 and (s1[2]==s2[2]+1 or s1[2]==s2[2]-1)){
		a[3]=1;
	}
	else{
		a[3]=0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
