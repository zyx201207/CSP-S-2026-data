#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	unsigned long long n;
	scanf("%ull",&n);
	string x="";
	for(int i=0;i<n;i++)
	{
		unsigned long long t;
		cin>>t;
		char s;
		cin>>s;
		for(int j=0;j<t;j++)
		{
			x+=s;
		}
	}
	cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
