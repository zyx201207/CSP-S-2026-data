#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	int cd=0;
	for(int i=1;i<=n;i++)
	{
		long long a;
		string c;
		cin>>a>>c;
		cd+=a;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	long long zj=cd/2;
	string q;
	string h;
	for(int i=0;i<zj;i++)
	{
		q+=s[i];
	}
	for(int i=cd-1;i>cd-zj-1;i--)
	{
		h+=s[i];
	}
	int sum=0;
	for(int i=0;i<zj;i++)
	{
		if(q[i]!=h[i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}