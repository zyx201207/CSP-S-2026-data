#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    bool f1=false,f2=false,f3=false,f4=false;
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) 
	{
		if(f1==false)
		{
			cout<<1;
			f1==true;		
		}
	}
	else if(f1==false){
		cout<<0;
		f1==true;
	}
//02 01C 02 01A
	if(a1==b1&&a2[1]==b2[1]&&a2[0]==b2[0]&&f2==false)
	{
		cout<<1;
		f2==true;
	}
	else cout<<0;
	if(a1==b1&&a2[1]==b2[1]&&a2[0]==b2[0])
	{
		char a=a2[2],b=b2[2];
		if(((a=='D'||a=='F')&&(b=='D'||b=='F'))||((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')))
		{
			cout<<1;
			f3==true;
		}
		else
		{
			if(f3==false)
			{
				cout<<0;
				f3=true;
			}
		}
	}
	else 
	{
		if(f3==false)
			{
				cout<<0;
				f3=true;
			}
	}
	if(a1==b1&&a2[1]==b2[1]&&a2[0]==b2[0])
	{
		char a=a2[2],b=b2[2];
		if(((a=='D'||a=='F')&&(b=='D'||b=='F'))||((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C')))
		{
			if(((a=='A'||a=='B')&&(b=='A'||b=='B'))||((a=='C'||a=='B')&&(b=='C'||b=='B'))||((a=='D'||a=='F')&&(b=='D'||b=='F')))
			{
				cout<<1;
				f4=true;
			}
			else 
			{
				if(f4==false)
			{
				cout<<0;
				f4=true;
			}
			}
		}
		else
		{
			if(f4==false)
			{
				cout<<0;
				f4=true;
			}
		}
	}
	else 
	{
		if(f4==false)
			{
				cout<<0;
			}
	}
	return 0;
}
//02 01C 02 01A
