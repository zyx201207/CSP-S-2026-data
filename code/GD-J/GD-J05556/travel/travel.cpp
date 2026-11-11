#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5];
int a,b,c1,c2;
bool f1,f2,f3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	f3=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		f3=1;
	}
	else cout<<"0";
	a=b=0;
	for(int i=0;i<=1;i++){
		a=a*10+(s1[i]-'0');
		b=b*10+(s2[i]-'0');
	}
	f1=1;
	f2=0;
	if(a==b&&f3==1) cout<<"1";
	else{
		cout<<"0";
		f1=0;
	}
	if(s1[2]=='A'&&s2[2]=='B') f2=1;
	else if(s1[2]=='A'&&s2[2]=='C') f2=1;
	else if(s1[2]=='B'&&s2[2]=='C') f2=1;
	else if(s1[2]=='D'&&s2[2]=='F') f2=1;
	else if(s2[2]=='A'&&s1[2]=='B') f2=1;
	else if(s2[2]=='A'&&s1[2]=='C') f2=1;
	else if(s2[2]=='B'&&s1[2]=='C') f2=1;
	else if(s2[2]=='D'&&s1[2]=='F') f2=1;
	if(f1==1&&f2==1&&f3==1) cout<<"1";
	else cout<<"0";
	if(abs(s1[2]-s2[2])==1&&f1==1&&f2==1&&f3==1) cout<<"1";
	else cout<<"0";
	return 0;
} 
