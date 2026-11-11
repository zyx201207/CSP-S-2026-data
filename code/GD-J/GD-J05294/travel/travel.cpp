#include<bits/stdc++.h>
using namespace std;
int r,x;
string c1,c2,s1,s2;
char ch1,ch2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')r=r*10+(s1[i]-'0');
		else ch1=s1[i];
		if(s2[i]>='0'&&s2[i]<='9')x=x*10+(s2[i]-'0');
		else ch2=s2[i];
	}
	if(r==x)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(ch1>='A'&&ch1<='C'&&ch2>='A'&&ch2<='C'||(ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(ch1-1==ch2||ch1+1==ch2||(ch1=='D'||ch1=='F')&&(ch2=='D'||ch2=='F'))cout<<1;
	else cout<<0;
	return 0;
} 
