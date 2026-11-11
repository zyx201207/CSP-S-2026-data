#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int ss1=0,ss2=0;
	int b[4]={0};
	if(c1==c2)
	{
		b[0]=1;
	}
	else
	{
		for(int i=0;i<4;i++)
		cout<<b[i];
		return 0;
	}
	
	
	for(int i=0;i<2;i++)
	{
		ss1=ss1*10+s1[i];
		ss2=ss2*10+s2[i];
	}
	
	if(ss1==ss2)
	b[1]=1;
	else
	{
		for(int i=0;i<4;i++)
		cout<<b[i];
		return 0;
	}
	char sss1=s1[2],sss2=s2[2];
	if(sss1<='C'&&sss2<='C')
	b[2]=1;
	else if(sss1>'C'&&sss2>'C')
	b[2]=1;
	else
	{
		for(int i=0;i<4;i++)
		cout<<b[i];
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F')
	b[3]=1;
	else if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
	b[3]=1;
	else
	b[3]=0;
	for(int i=0;i<4;i++)
		cout<<b[i];
	return 0;
}
