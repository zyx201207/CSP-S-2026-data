#include <bits/stdc++.h>
using namespace std;
int n,a,sum=0;
string s,x,y;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++)
	{
		cin >> a >> c;
		while(a--)
		{
			s+=c;
		}
	}
	int mid=s.length()/2;
	for(int i = 0;i<mid;i++)
	{
		if(s[i]!=s[s.length()-i-1])sum++;
	}
	cout << sum;
	return 0;
}
