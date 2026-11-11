//GZ-J00406  ËçÑôÏØËçÑôÖÐÑ§ ÌïÑÔÎ÷  
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r[2],x[2];
	cin>>r[0]>>r[1];
	cin>>x[0]>>x[1];
	
	if(r[0][0]==x[0][0]&&r[0][1]==x[0][1])cout<<1;
	else 
	{
		for(int i=0;i<4;i++)cout<<0;
		return 0;
	}
	
	if(r[1][0]==x[1][0]&&r[1][1]==x[1][1])
	{
		cout<<1;
	}
	else 
	{
		for(int i=0;i<3;i++)cout<<0;
		return 0;
	}
	
	if(r[1][2]=='D'&&x[1][2]=='F')
	{
		for(int i=0;i<2;i++)cout<<1;
		return 0;
	}
	if(x[1][2]=='D'&&r[1][2]=='F')
	{
		for(int i=0;i<2;i++)cout<<1;
		return 0;
	}
	if(x[1][2]=='A'||x[1][2]=='B'||x[1][2]=='C')
	{
		if(r[1][2]=='A'||r[1][2]=='B'||r[1][2]=='C')
		cout<<1;
	}
	else{
		for(int i=0;i<2;i++)cout<<0;
		return 0;
	}
	if(r[1][2]=='C'&&x[1][2]=='B')
	{
		cout<<1;
		return 0;
	}
	if(r[1][2]=='B')
	{
		cout<<1;
		return 0;
	}
	if(r[1][2]=='A'&&x[1][2]=='B')
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}

