#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a;
	string c;
	string s;
	int q=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>c;
		q+=a;
		for (int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	int cnt=0;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]!=s[q+1-i])
		{
			s[q+1-i]=s[i];
			cnt++;
		}
	}
	cout<<cnt;	
	return 0;
}
