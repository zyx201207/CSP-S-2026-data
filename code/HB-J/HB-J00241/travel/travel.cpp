#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a[0]==b[0]&&a[1]==b[1])
	{
		cout<<1;
		if(aa[0]==bb[0]&&aa[1]==bb[1])
		{
			cout<<1;
			if((aa[2]=='A'&&(bb[2]=='B'||bb[2]=='C'))||(aa[2]=='B'&&(bb[2]=='A'||bb[2]=='C'))||(aa[2]=='C'&&(bb[2]=='B'||bb[2]=='A')))
			{
				cout<<1;
				if(aa[2]=='A')
				{
					if(bb[2]=='B')cout<<1;
					else cout<<0;
				}
				else if(aa[2]=='B')
				{
					if(bb[2]=='A'||bb[2]=='C')cout<<1;
					else cout<<0;
				}
				else if(aa[2]=='C')
				{
					if(bb[2]=='B')cout<<1;
					else cout<<0;
				}
			}
			else if((aa[2]=='D'&&bb[2]=='F')||(aa[2]=='F'&&bb[2]=='D'))
			{
				cout<<1<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else 
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	return 0;
}
