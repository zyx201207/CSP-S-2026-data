#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[2]==c2[2]){cout<<1;}
	else{
	cout<<0;
	cout<<0;
	cout<<0;
	cout<<0;
	return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]!=s2[2]){cout<<1;}
	else{
	cout<<0;
	cout<<0;
	cout<<0;
	return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
	cout<<1;
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
	cout<<0;
	cout<<0;}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
