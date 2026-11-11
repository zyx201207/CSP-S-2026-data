#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int c11=(c1[0]-'0')*10+c1[1]-'0',c22=(c2[0]-'0')*10+c2[1]-'0';\
	if(c11==c22)
	{
		cout<<1;
		int c3=(s1[0]-'0')*10+s1[1]-'0',c4=(s2[0]-'0')*10+s2[1]-'0';
		if(c3==c4)
		{
			cout<<1;
			if(s1[2]>='D'&&s2[2]>='D')
			{
				cout<<1;
				if((s1[2]=='F'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='F'))cout<<1;
				else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))cout<<1;
				else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))cout<<1;	
				else cout<<0;
			}
			else if(s1[2]<='C'&&s2[2]<='C')
			{
				cout<<1;
				if((s1[2]=='F'&&s2[2]=='E')||(s1[2]=='E'&&s2[2]=='F'))cout<<1;
				else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A'))cout<<1;
				else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C'))cout<<1;	
				else cout<<0;
			}
			else cout<<"00"; 
		}
		else cout<<"000";
		
	}
	else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
