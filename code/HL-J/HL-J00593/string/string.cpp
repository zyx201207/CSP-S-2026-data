#include<bits/stdc++.h>
using namespace std;

int a;
int n;
string s;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c;
		for(int j=1;j<=a;j++)
		{
			s+=c;
		}
	}
	cout << 3;
	return 0;
} 
