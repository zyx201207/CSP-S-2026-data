#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a[200005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long q;
		char c;
		cin>>q>>c;
		for(int j=1;j<=q;j++)
		{
			a[i]+=c;
		}
	}
	string x;
	for(int i=1;i<=n;i++)
	{
		x+=a[i];	
	}
	string y=x;
	reverse(x.begin(),x.end());
	if(x==y)
	{
		cout<<0;
	}
	else
	{	
		int q=y.size();
		if(q%2==0)
		{
			if(y[q/2]!=y[q/2-1])
			{
				cout<<q/2;
			}	
			else
			{
				cout<<q/2-1;
			}
		}
		else
		{
			cout<<(q-1)/2;
		}
	}
	return 0;
}
