#include<bits/stdc++.h>
using namespace std;
string c,s,c22,s22;
bool b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c22>>s22;//车厢号 座位号
	if(c==c22)
	{
		cout<<'1';
		for(int i=0;i<s.size();i++)
		{
			if(s[i+1]>='0'&&s[i+1]<='9'&&s[i]>='0'&&s[i]<='9'&&s22[i+1]>='0'&&s22[i+1]<='9'&&s22[i]>='0'&&s22[i]<='9')
			{
				if(s[i]==s22[i]&&s22[i+1]==s[i+1])
				{
					cout<<'1';
					b=1;
				}
				else
					cout<<'0';
			}//排 
			
			if(s[i]>='A'&&s[i]<='Z'&&s22[i]>='A'&&s22[i]<='Z')
			{	
				if(s[i]>='A'&&s[i]<='C'&&s22[i]>='A'&&s22[i]<='C'&&b==1)
				{
					cout<<'1';
					if(s[i]=='A'&&s22[i]=='B')
					{
						cout<<'1';
					}
					else if(s[i]=='B'&&s22[i]=='C')
						cout<<'1';
					else
					{
						cout<<'0';
					}
				}
				else if(s[i]>='D'&&s[i]<='F'&&s22[i]>='D'&&s22[i]<='F'&&b==1)
				{
					cout<<'1';
						cout<<'1';
					//相邻 
				} 	
				else
				cout<<"00";//同一侧 
			} 
		}
	} 
	else
	{
		cout<<"0000";
	}
	return 0;
}
