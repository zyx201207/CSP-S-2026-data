#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){	
	freopen("traval.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int p1=(s1[0]-'0')*10+s1[1]-'0',p2=(s2[0]-'0')*10+s2[1]-'0';
	if(p1==p2)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	char ch1=s1[2],ch2=s2[2];
	if((abs(ch1-ch2)==1)&&!((ch1=='C'&&ch2=='D')||(ch1=='D'&&ch2=='C')))cout<<1;
	else cout<<0;
	return 0;
}
