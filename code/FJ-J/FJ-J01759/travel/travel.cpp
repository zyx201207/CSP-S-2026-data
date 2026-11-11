#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
	{
		cout<<1;
		string r1=s1.substr(0,2);
		string r2=s2.substr(0,2);
		if(r1==r2)
		{
			cout<<1;
			string es1=s1.substr(2,1);
			string es2=s2.substr(2,1);
			if(((es1=="A"||es1=="B"||es1=="C")&&(es2=="A"||es2=="B"||es2=="C"))||((es1=="D"||es1=="F")&&(es2=="D"||es2=="F")))
			{
				cout<<1;
				if((es1=="A") && (es2=="B"))
				{
					cout<<1;
					return 0;
				}
				if(es1=="B"&&es2=="A")
				{
					cout<<1;
					return 0;
				}
				if(es1=="B"&&es2=="C")
				{
					cout<<1;
					return 0;
				}
				if(es1=="C"&&es2=="B")
				{
					cout<<1;
					return 0;
				}
				if(es1=="D"&&es2=="F")
				{
					cout<<1;
					return 0;
				}
				if(es1=="F"&&es2=="D")
				{
					cout<<1;
					return 0;
				}
				cout<<"0";
				return 0;
			}else
			{
				cout<<"00";
					return 0;
			}
			
		}else
		{
			cout<<"000";
			return 0;
		}
	}else
	{
		cout<<"0000";
		return 0;
	}
	
	
} 
