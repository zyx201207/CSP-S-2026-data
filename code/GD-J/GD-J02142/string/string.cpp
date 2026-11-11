#include <iostream>
using namespace std;
long long a[212345];
char c[212345];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long s=0;
	cin >>n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i]>>c[i];
		s+=a[i];
	}
	string st;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<a[i];j++)
		{
			st+=c[i];
		}
	}
//	cout <<st;
	long long ans=s/2;
	for (int i=0;i<s/2;i++)
	{
//		cout << st[i]<<" " << st[s-1-i]<<'\n';
		if(st[i]==st[s-i-1])ans--;
	}
	cout <<ans;
	return 0;
} 
