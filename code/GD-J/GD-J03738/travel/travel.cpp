#include <bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2,s3,sa,sb,sc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>s2>>s3>>c2>>sa>>sb>>sc;
	
	if(c1=="01"||c1=="16"||c2=="01"||c2=="16")
	{
		cout<<"0000";
		return 0;
	}

	else
	{
		if(c1==c2) cout<<"1";
		else
		{
			cout<<"0000";
			return 0;
		}

		if(s1==sa&&s2==sb) cout<<"1";
		else
		{
			cout<<"000";
			return 0;
		}
		
		if(s3>='A'&&s3<='C'&&sc>='A'&&sc<='C')
		{
			cout<<"1";
		}
		else if(s3>='D'&&s3<='F'&&sc>='D'&&sc<'F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
		
		if(s3>='A'&&s3<='C'&&sc>='A'&&sc<='C')
		{
			if(s3=='A'&&sc=='B') cout<<"1";
			else if(s3=='B'&&sc=='C') cout<<"1";
			else if(s3=='C'&&sc=='B') cout<<"1";
			else if(s3=='B'&&sc=='A') cout<<"1";
			else
			{
				cout<<"0";
				return 0;
			}
		}
		else if(s3>='D'&&s3<='F'&&sc>='D'&&sc<='F')
		{
			if(s3=='D'&&sc=='F') cout<<"1";
			else if(s3=='F'&&sc=='D') cout<<"1";
			else
			{
				cout<<"0";
				return 0;
			}
		}
	}
	return 0;
}
