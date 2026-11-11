#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	string x=b.substr(2);
	string y=d.substr(2);
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2))cout<<1;
	else cout<<0;
	if(a==c&&b.substr(0,2)==d.substr(0,2))
	{
		if((x=="D"&&y=="F")||(x=="F"&&y=="D")||(x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="B"&&y=="C")||(x=="C"&&y=="B")||(x=="A"&&y=="C")||(x=="C"&&y=="A"))
		{
			f=1;
			cout<<1;
		}
	}
	if(f==0)cout<<0;
	f=0;
	if(a==c&&b.substr(0,2)==d.substr(0,2))
	{
		if((x=="D"&&y=="F")||(x=="F"&&y=="D")||(x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="B"&&y=="C")||(x=="C"&&y=="B"))
		{
			f=1;
			cout<<1;
		}
	}
	if(f==0)cout<<0;
	return 0;
} 
