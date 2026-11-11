#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s1;
	
	for(int i=1;i<=n;i++)
	{
		long long b;
		cin >> b;
		char a;
		cin >> a;
		for(int i=1;i<=b;i++)
		{
			s1+=a;
		}
	}
	
	string s2;
	for(int i=s1.size()-1;i>=0;i--)
	{
		s2+=s1[i];
	}
	
	int cnt=0;
	for(int i=0;i<=s1.size()/2-1;i++)
	{
		if(s2[i]!=s1[i])
		{
			s2[i]=s1[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;	
}
