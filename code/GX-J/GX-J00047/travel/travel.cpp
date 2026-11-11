#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string s3;
	string s4;
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	if(s1==s3)
	{
		cout<<1;
		for(int i=0;i<s2.size()-1;i++)
		{
			if(s2[i]==s4[i] && s2[i+1]==s4[i+1])
			{
				cout<<1;
				break;
			}
			else
			cout<<0;
		}
		if((s2[2]=='D' && s4[2]=='F') || (s4[2]=='D' && s2[2]=='F'))
		cout<<11;
		else if((s2[2]=='A' && s4[2]=='B') || (s4[2]=='A' && s2[2]=='B'))
		cout<<11;
		else if((s2[2]=='B' && s4[2]=='C') || (s4[2]=='B' && s2[2]=='C'))
		cout<<11;
		else if((s2[2]=='A' && s4[2]=='C') || (s4[2]=='A' && s2[2]=='C'))
		cout<<"10";
		else
		cout<<"00";
	}
	
	else
	cout<<"0000";
	
		return 0;
}
