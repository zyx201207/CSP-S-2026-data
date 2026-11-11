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
	else
	{
		int a,b;
		char c,d;
		cin>>a>>c>>b>>d;
		if(c==d)
		{
			cout<<0;
			return 0;
		}
		else {
			cout<<min(a,b);
			return 0;
		}
	}	
	return 0;
}
