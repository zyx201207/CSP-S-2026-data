#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
string c1,c2,s1,s2;
int flag;
int main()
{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		cin>>c1>>c2>>s1>>s2;
		int len1=c1.size();
		int len2=c2.size();
		for(int i=1;i<=len1-1;i++)
		{
			if(c1[i]==s1[i])
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}			
		if(flag==1)
				cout<<"1";
		else
		{
			cout<<"0000";
			return 0;	
		}
		flag=0;		
		for(int j=1;j<=len2-2;j++)
		{
			if(c2[j]==s2[j])
				flag=1;
			else
			{
				flag=0;
				break;
			}		
		}	
		if(flag==0)
		{
			cout<<"000";
			return 0;
		}		
		else
			cout<<"1";	
		if(('C'<c2[len2-1]&&'C'<s2[len2-1])||(c2[len2-1]<='C'&&s2[len2-1]<='C'))
			cout<<"1";
		else
		{
			cout<<"00";
			return 0;
		}	
		if((c2[len2-1]=='A'&&s2[len2-1]=='B')||(c2[len2-1]=='B'&&s2[len2-1]=='A')||(c2[len2-1]=='B'&&s2[len2-1]=='C')||(c2[len2-1]=='C'&&s2[len2-1]=='B')||(c2[len2-1]=='D'&&s2[len2-1]=='E')||(c2[len2-1]=='E'&&s2[len2-1]=='D'))
			cout<<1;
		else
			cout<<"0";	
		return 0;			
}
