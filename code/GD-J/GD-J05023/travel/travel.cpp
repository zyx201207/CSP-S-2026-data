#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1=1,f2=1,f3=1,f4=1;
int main(){
	
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=max(c1.size(),c2.size());i++)
	{
		if(c1[i]!=c2[i]){
			f1=0;
			f2=0;
			f3=0;
			f4=0;
			break;	
		}	
	}
	for(int i=0;i<=max(s1.size(),s2.size());i++)
	{
		if(s2[i]>='0'&&s2[i]<='9'&&s1[i]>='0'&&s1[i]<='9'&&s1[i]!=s2[i]){
			f2=0;
			f3=0;
			f4=0;
			break;
		}	
	}
	
	for(int i=0;i<=max(s1.size(),s2.size());i++)
	{
		if(s2[i]>='A'&&s2[i]<='F'&&s1[i]>='A'&&s1[i]<='F'){
			if(s1[i]=='F'&&s2[i]!='D')
			{
				f3=0;
				f4=0;
				break;
			}
			if(s1[i]=='D'&&s2[i]!='F')
			{
				f3=0;
				f4=0;
				break;
			}
			if(s1[i]=='C'&&s2[i]!='B')
			{
				f4=0;
				if(s1[i]=='C'&&s2[i]!='A'){
					f3=0;
				}
				break;
			}
			if(s1[i]=='B'&&s2[i]!='C'&&s2[i]!='A')
			{
				f3=0;
				f4=0;
				break;
			}
			if(s1[i]=='A'&&s2[i]!='B')
			{
				f4=0;
				if(s1[i]=='A'&&s2[i]!='C'){
					f3=0;
				}
				break;
			}
		}	
	}	
	if(f1)
	{
		cout<<"1";
	}
	else cout<<"0";
	
	if(f2)
	{
		cout<<"1";
	}
	else cout<<"0";
	
	if(f3)
	{
		cout<<"1";
	}
	else cout<<"0";
	
	if(f4)
	{
		cout<<"1";
	}
	else cout<<"0";
	
	return 0;
} 
