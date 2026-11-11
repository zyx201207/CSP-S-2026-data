#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100010;

int a[N];
char c[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n, cnt = 0;
	string s = "";
	cin>>n;
	
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		
		for(int j = 1;j<=a[i];j++)
		{
			s += c[i];
		}
	}
	
	for(int i = 0,j=s.size()-1;i<=s.size()/2;i++,j--)
	{
		if(s[i] != s[j]) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}
