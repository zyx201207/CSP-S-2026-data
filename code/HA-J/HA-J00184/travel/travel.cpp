#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=+5;
int n;
string sa,sb,sa2,sb2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>sa>>sa2>>sb>>sb2;
	if(sa==sb)
	{
		if(sa2[0]==sb2[0] && sa2[1]==sb2[1])
		{
			if((sa2[2]<='C' && sb2[2]<='C') || (sa2[2]>'C' && sb2[2]>'C'))
			{
				if(abs(sa2[2]-sb2[2])==1)
				{
					cout<<1111;
				}
				else
				{
					cout<<1110;
				}
			}
			else
			{
				cout<<1100;
			}
		}
		else
		{
			cout<<1000;
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
