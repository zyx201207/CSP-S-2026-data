#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a1[13],a2[13];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else 
	{
		cout<<"0000";
		return 0;	
	}
	for(int i=0;i<s1.size();i++) a1[i]=s1[i];
	for(int i=0;i<s2.size();i++) a2[i]=s2[i];
	if(a1[0]==a2[0]&&a1[1]==a2[1])
	{
		cout<<"1";
		if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'))
		{
			cout<<"1";
			if((a1[2]=='A'&&a2[2]=='B')||(a1[2]=='B'&&a2[2]=='C')) cout<<"1"<<endl;
			else if((a2[2]=='A'&&a1[2]=='B')||(a2[2]=='B'&&a1[2]=='C')) cout<<"1"<<endl;
			else cout<<"0";
		} 
		else if((a1[2]=='D'||a1[2]=='F')&&(a1[2]=='D'||a2[2]=='F'))
		{
			cout<<"1";
			if(a1[2]=='D'&&a2[2]=='F') cout<<"1"<<endl;
			else if(a2[2]=='D'&&a1[2]=='F') cout<<"1"<<endl;
			else cout<<"0";
		}
		else cout<<"00";
	}
	else
	{
		cout<<"000";	
	} 
	return 0;
}
