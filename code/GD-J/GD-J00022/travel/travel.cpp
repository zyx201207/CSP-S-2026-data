#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
char mu1,mu2;
int solv(char mu)
{
	if(mu>='A'&&mu<='C')
	{
		return 1;
	}
	if(mu=='D'||mu=='F')
	{
		return 2;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool ok=false;
	cin>>s1>>s2>>s3>>s4;
	s1=' '+s1;//车厢号 
	s2=' '+s2;//座位号 
	s3=' '+s3;//车厢号 
	s4=' '+s4;//座位号 
	if(s1==s3)
	{
		cout<<'1';
	}
	else{
		ok=true;
		cout<<'0';
	}
	
	string str1,str2;
	str1=' ',str2=' ';
	int k=1;
	while(s2[k]>='0'&&s2[k]<='9'&&k<s2.size())
	{
		str1+=s2[k];
		k++;
	}
	mu1=s2[k];
	k=1;
	while(s4[k]>='0'&&s4[k]<='9'&&k<s4.size())
	{
		str2+=s4[k];
		k++;
	}
	mu2=s4[k];
	if(ok==true)
	{
		cout<<0;
	}
	else{
		if(str1==str2)
		{
			cout<<1;
		}
		else{
			ok=true;
			cout<<0;
		}
	}
	if(ok==true)
	{
		cout<<0;
	}
	else{
		if(solv(mu1)==solv(mu2))
		{
			cout<<1;
		}
		else{
			ok=true;
			cout<<0;
		}
	}
	if(ok==true)
	{
		cout<<0;
	}
	else{
		if(mu1-mu2==1||mu1-mu2==-1||(mu1=='D'&&mu2=='F')||(mu1=='F'&&mu2=='D'))
		{
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	return 0;	
} // 
