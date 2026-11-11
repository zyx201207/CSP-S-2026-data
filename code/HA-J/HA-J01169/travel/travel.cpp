#include <bits/stdc++.h>
using namespace std;
int main() {
	int c1,c2;
	char s11,s12,s13,s21,s22,s23;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s11>>s12>>s13;
	cin>>c2;
	cin>>s21>>s22>>s23;
	if(c1==c2)
	{
		cout<<1<<endl;
		if(s11==s21 and s12==s22)
		{
			cout<<1<<endl;
			if((s13>='A' and s13<='C' and s23>='A' and s23<='C' ) or (s13>='D' and s13<='F' and s23>='D' and s23<='F' ))
			{
				cout<<1<<endl;
				if(s13+1==s23 or s13-1==s23)
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
				cout<<0<<endl<<0;
			}
		}
		else
		{
			cout<<0<<endl<<0<<endl<<0;
		}
	}
	else
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}
