#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char str1[5]={'A','B','C','D','F'};
	cin>>c1>>s1>>c2>>s2;
	int f=1;
	for(int i=0;i<=c1.size();i++){
		if(c1[i]!=c2[i])f=0;
	}
	cout<<f;
	if(f==0){cout<<"000";return 0;}
	f=1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i])f=0;
	}
	cout<<f;
	if(f==0){cout<<"00";return 0;}
	f=0;
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D')f=1;
	cout<<f;
	if(f==0){cout<<"0";return 0;}
	f=0;
	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='F')f=1;
	cout<<f;
	return 0; 
} 
