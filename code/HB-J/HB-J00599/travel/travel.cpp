#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a1,a2;
char h,hh;
int q,qq;
int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	
	if(c1==c2)
	{
		int l=s1.size();
		int ll=s2.size();
		for(int i=0;i<l-1;i++)
		{
			a1+=s1[i];
		}
		for(int i=0;i<ll-1;i++)
		{
			a2+=s2[i];
		}
		h=s1[l-1];
		hh=s2[ll-1];
		if(a1!=a2)
		{
			cout<<"1000";
			return 0;
		}
		else if(a1==a2)
		{
			cout<<"11";
			if((h>='A'&&h<='C')&&(hh>='A'&&hh<='C'))
			{
				cout<<"1";
				q=s1[l-1]-'A'+1;
				qq=s2[ll-1]-'A'+1;
				int k=abs(q-qq);
				if(k==1)
				{
					cout<<"1";
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			}
			else if((h>='D'&&h<='F')&&(hh>='D'&&hh<='F'))
			{
				cout<<"11";
				
			}
			else
			{
				cout<<"00";
				return 0;
			}
			
		}
	}
	return 0;
}
//Trick||Treat!
