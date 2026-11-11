#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char a,b;
	cin>>c1>>s1>>a>>c2>>s2>>b;
	if(c1==c2)
	{
		cout<<1;
		if(s1==s2)
		{
			cout<<1;
			if((a>='D'&&b>='D')||(a<='C'&&b<='C'))
			{
				cout<<1;
				if(a-b==1||b-a==1)
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
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
