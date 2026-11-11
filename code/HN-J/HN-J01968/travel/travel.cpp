#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]==c2[i]&&c1[i+1]==c2[i+1])
		{
			cout<<1;
			break;
		}
		else {
		cout<<0;
		break;
		}
	}
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]==s2[i]&&s1[i+1]==s2[i+1])
		{
			cout<<1;
			break;
		}else{
			cout<<0;
			break;
		}
	}
	for(int i=s1.size();i>0;i--)
	{
		if(s1[i]>='A'&&s1[i]<='C'&&s2[i]>='A'&&s2[i]<='C')
		{
		cout<<1;
			if(int(s1[i])+1!=int(s2[i])||int(s1[i])-1!=int(s2[i]))
			{
				cout<<0;
			}
			else {
				cout<<1;
			}
		}
		else if(s1[i]>='D'&&s1[i]<='F'&&s2[i]>='D'&&s2[i]<='F')
		{
			cout<<11;
			
		}
		else {cout<<0;
		break;
		}
	}
	return 0;
}
