#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("trave.in.txt","r",stdin);
	freopen("trave.out.txt","w",stdout);
	int n,q;
	string m,p;
	cin>>n>>m>>q>>p;
	if(n!=q)
	{
	 	cout<<0<<0<<0<<0;
	}
	else
	{
		if(m[0]==p[0]&&m[1]==p[1])
		{
			if(m[3]+'1'==p[3]&&p[3]!='D'||m[3]-'1'==p[3]&&p[3]!='C')
			{
				
				
			}
			else
			{
				cout<<11<<0<<0;
			}
		}
		else
		{
			cout<<1<<0<<0<<0;
		}
	}
}
