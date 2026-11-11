#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int s3[10],s4[10];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else cout<<"0";
	for(int i=0;i<s1.size();i++)
	{
		if(i==2) break;
		s3[i]=s1[i]-'0';
	}
	for(int i=0;i<s2.size();i++)
	{
		if(i==2) break;
		s4[i]=s2[i]-'0';
	}
	if(s3[0]==s4[0]&&s3[1]==s4[1]&&c1==c2)
	{
		cout<<"1";
	}
	else cout<<"0";
	if(s3[0]==s4[0]&&s3[1]==s4[1]&&c1==c2)
	{
		if(s1[2]-'A'>=0&&s1[2]-'A'<=2&&s2[2]-'A'>=0&&s2[2]-'A'<=2||s1[2]-'A'==3&&s2[2]-'A'==5||s2[2]-'A'==3&&s1[2]-'A'==5)
		{	
			cout<<"1";
		}
		else cout<<"0";	
	}
	else cout<<"0";	
    if(s3[0]==s4[0]&&s3[1]==s4[1]&&c1==c2)
	{
		if(s1[2]-'A'>=0&&s1[2]-'A'<=2&&s2[2]-'A'>=0&&s2[2]-'A'<=2||s1[2]-'A'==3&&s2[2]-'A'==5||s2[2]-'A'==3&&s1[2]-'A'==5)
		{	
			if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
			{
				cout<<"1";
			}
			else cout<<"0";	
		}
		else cout<<"0";	
	}	
		else cout<<"0";	
	
	
	return 0;
}