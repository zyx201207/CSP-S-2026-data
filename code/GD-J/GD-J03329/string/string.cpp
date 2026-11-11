#include<bits/stdc++.h>
using namespace std;
string S[500000];
int main()
{
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,b=0;
	string c;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>c;
		for(int j=0;j<a;j++)
		{
			S[j]=c;
			b++;
		}
	}
	string d[b];
	for(int i=0;i<b;i++)
	{
		d[i]=S[i];
	}
	cout<<0;
	return 0;
}
