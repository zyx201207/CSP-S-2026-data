#include<bits/stdc++.h>
using namespace std;
int p,p2,p3,p4;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<s1.size();i++)if(i!=0||s1[i]!='0')p=p*10+s1[i]-'0';
	for(int i=0;i<s3.size();i++)if(i!=0||s3[i]!='0')p2=p2*10+s3[i]-'0';
	if(p==p2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s2.size()-1;i++)if((i!=0||s2[i]!='0')&&(s2[i]<'A'||s2[i]>'Z'))p3=p3*10+s2[i]-'0';
	for(int i=0;i<s4.size()-1;i++)if((i!=0||s4[i]!='0')&&(s4[i]<'A'||s4[i]>'Z'))p4=p4*10+s4[i]-'0';
	if(p3==p4)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char c1=s2[s2.size()-1],c2=s4[s4.size()-1];
	if(c1=='F'||c1=='D')cout<<1;
	else if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B')||(c1=='A'&&c2=='C')||(c1=='C'&&c2=='A'))cout<<1;
	else cout<<0;
	if(c1=='F'||c1=='D')cout<<1;
	else if((c1=='A'&&c2=='B')||(c1=='B'&&c2=='C')||(c1=='B'&&c2=='A')||(c1=='C'&&c2=='B'))cout<<1;
	else cout<<0;
	return 0;
}
