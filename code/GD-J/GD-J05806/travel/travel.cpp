#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<1;
			bool ce1=0,ce2=0;
			if(s1[2]=='D'||s1[2]=='E')ce1=1;
			if(s2[2]=='D'||s2[2]=='E')ce2=1;
			if(ce1==ce2)
			{
				cout<<1;
				if(ce1)cout<<1;
				if(!ce1)
				{
					if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))cout<<0;
					else cout<<1;
				}
			}
			else cout<<"00";
		}
		else cout<<"000";
		
	}
	else 
	{
		cout<<"0000";
	}
	return 0;
}
