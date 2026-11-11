#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,ans="0000";
	int a2,b2;
	char a3,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	if(a1==b1)
	{
		ans[0]='1';
		if(a2==b2)
		{
			ans[1]='1';
			if((a3<='C' && b3<='C') || (a3>'C' && b3>'C'))
			{
				ans[2]='1';
				if(a3+1==b3 || b3+1==a3) ans[3]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}
