#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool wrong=true;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i]) wrong=false;
	}
	if(wrong)
	{
		bool wrong1=true;
		cout<<"1";
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i]) wrong1=false;
		}
		if(wrong1)
		{
			cout<<"1";
			bool wrong2=false;
			if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C')) wrong2=true;
			if(wrong2)
			{
				cout<<"1";
				bool wrong3=false;
				if(abs(s1[2]-s2[2])==1)
				cout<<"1";
				else cout<<"0";
			}
			else{
				cout<<"0"<<"0";
			}
		}
		else{
			cout<<"0"<<"0"<<"0";
		}	
	}
	else
	{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	return 0;
}
