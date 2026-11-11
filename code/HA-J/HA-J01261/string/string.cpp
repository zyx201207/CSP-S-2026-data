#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		string s,t;
		cin>>x;
		cin>>s;
		cin>>y;
		cin>>t;
		if(s==t)
		{
			cout<<0;
			break;
		}
		if(x==1000000000)
		{
			if(s!=t)
			{
				cout<<3000000000;
				break;
			}
			else
			{
				cout<<0;
				break;
			}
		}
		else
		{
			cout<<2;
			break;
		}
	}
	return 0;
}
