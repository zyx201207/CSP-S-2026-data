#include<bits/stdc++.h>
using namespace std;
int x,y;
string n,m;
int main() 
{ 
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>x>>n>>y>>m;       
	if(x==y) cout<<1;
	else 
	{
		cout<<"0000"<<endl;
		return 0;
	}
	int x1=(n[0]-'0')*10+(n[1]-'0');   
	int x2=(m[0]-'0')*10+(m[1]-'0');
	if(x1==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000"<<endl;
		return 0;
	}
	char a=n[2];
	char b=m[2];
	if((a<='C'&&b<='C')||(a>='D'&&b>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<"00"<<endl;
		return 0; 
	}    
	if((a+1==b||(a=='D'&&b=='F'))||(b+1==a||(a=='F'&&b=='D')))
	{
		cout<<1<<endl;
	}
	else 
	{ 
		cout<<0<<endl;
	}
	return 0; 
} 
