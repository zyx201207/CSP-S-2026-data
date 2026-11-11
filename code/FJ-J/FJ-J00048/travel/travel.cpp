#include <bits/stdc++.h>
using namespace std;
string a,b;
int c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>a>>d>>b;
	if(c==01||c==16||d==01||d==16)
	{
		cout<<0000;
		return 0;
		
	}
	if(c==d)
	{cout<<1;
		if(a[0]==b[0]&&a[1]==b[1])
		{
			cout<<1;
			if((a[2]<'D'&&b[2]<'D')||(a[2]>'C'&&b[2]>'C'))
			{
				cout<<1;
				if(a[2]+1==b[2]||a[2]-1==b[2])cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		} 
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	
	
	
	
	return 0;
}
