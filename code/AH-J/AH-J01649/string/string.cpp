#include<bits/stdc++.h>
using  namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	char c;
	string f={};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int i=1;i<=a;i++)
		{
			f[i]=c;
		}
	}
	cout<<f.size();
	return 0;
}
