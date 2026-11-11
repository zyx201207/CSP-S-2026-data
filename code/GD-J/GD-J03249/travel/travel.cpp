#include <bits/stdc++.h>
using namespace std;
bool abc(char n,char m){
	if(n=='D'&&m=='C')
	    return 0;
	else if(n=='C'&&m=='D')
	    return 0;
	else
	{
		if(m=='F'||m=='D')
		{
			if(n=='F'||n=='D')
			    return 1;
		}
		else if(m=='A'||m=='B'||m=='C')
		{
			if(n=='A'||n=='B'||n=='C')
			    return 1;
		}
	}
	return 0;
}
bool abc2(char n,char m){
	if(n=='C'&&m=='D')
	    return 0;
	else if(n=='D'&&m=='C')
	    return 0;
	else
	{
		if(max(n,m)-min(m,n)==1)
		{
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)
	{
		cout<<1;
		if(a2[0]==b2[0]&&a2[1]==b2[1])
		{
			cout<<1;
			if(abc(a2[2],b2[2]))
			{
				cout<<1;
				if(abc2(a2[2],b2[2]))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
	    cout<<"0000";
	}
	return 0;
}
