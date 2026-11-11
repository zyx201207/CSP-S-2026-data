#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string v1,v2;
	cin>>c1>>v1>>c2>>v2;
	if(c1==c2)
	{
		cout<<1;
		if(v1[0]+v1[1]==v2[0]+v2[1])
		{
			cout<<1;
			int t1=(v1[2]-'A');
			int t2=(v2[2]-'A');
			if(t1<=2 && t2<=2)
			{
				cout<<1;
			 } 
			 else if(t1>2 && t2>2)
			 {
			 	cout<<1;
			 }
			 else cout<<0;
			 if(t1<=2 && t2<=2)
			{
				if(t1==t2+1 || t1==t2-1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			} 
			 else if(t1>2 && t2>2)
			 {
			 	if(t1==t2+1 || t1==t2-1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			 }
			 else cout<<0;
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
