#include<bits/stdc++.h>
using namespace std;
long long sum,a[200010],l;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++)
		{
			s+=c;
		}
	}
	l=s.size();
	for(int i=0;i*2<l;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
