#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		while(x--)
		{
			s=s+c;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
