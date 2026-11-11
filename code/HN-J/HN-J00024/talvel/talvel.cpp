#include<bits/stdc++.h>
using namespace std;
int a[5]={0,2,2,2,2};
int main(){
	freopen("talvel.in","r",stdin);
	freopen("talvel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
		a[1]=1;
	else
		a[1]=0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&a[1])
		a[2]=1;
	else
		a[2]=0;
	if(s2[2]=='A'){
		if((s4[2]=='B'||s4[2]=='C')&&a[2])
			a[3]=1;
		else
			a[3]=0;
	}
	if(s2[2]=='B'){
		if((s4[2]=='A'||s4[2]=='C')&&a[2])
			a[3]=1;
		else
			a[3]=0;
	}
	if(s2[2]=='C'){
		if((s4[2]=='A'||s4[2]=='B')&&a[2])
			a[3]=1;
		else
			a[3]=0;
	}
	if(s2[2]=='D'){
		if(s4[2]=='E'&&a[2])
			a[3]=1;
		else
			a[3]=0;
	}
	if(s2[2]=='E'){
		if(s4[2]=='D'&&a[2])
			a[3]=1;
		else
			a[3]=0;
	}
	if(s2[2]=='A'){
		if(s4[2]=='B'&&a[3])
			a[4]=1;
		else
			a[4]=0;
	}
	if(s2[2]=='B'){
		if(s4[2]=='A'&&a[3])
			a[4]=1;
		else if(s4[2]=='C'&&a[3])
			a[4]=1;
		else
			a[4]=0;
	}
	if(s2[2]=='C'){
		if(s4[2]=='B'&&a[3])
			a[4]=1;
		else
			a[4]=0;
	}
	if(s2[2]=='D'){
		if(s4[2]=='E'&&a[3])
			a[4]=1;
		else
			a[4]=0;
	}
	if(s2[2]=='E'){
		if(s4[2]=='D'&&a[3])
			a[4]=1;
		else
			a[4]=0;
	}
	if(a[1])
		cout<<1;
	else cout<<0;
	if(a[2])
		cout<<1;
	else cout<<0;
	if(a[3])
		cout<<1;
	else cout<<0;
	if(a[4])
		cout<<1;
	else cout<<0;
	return 0;
}
